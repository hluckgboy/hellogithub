#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Task structure to hold a function pointer and its argument
typedef struct {
    void (*function)(void *); // Task function
    void *arg;                // Task argument
} Task;

// ThreadPool structure to manage threads and tasks
typedef struct {
    pthread_mutex_t lock;      // Mutex to protect shared resources
    pthread_cond_t cond;       // Condition variable for task availability
    pthread_t *threads;        // Array of threads
    Task *task_queue;          // Circular queue for tasks
    int queue_size;            // Current number of tasks in the queue
    int queue_capacity;        // Maximum capacity of the task queue
    int head;                  // Index of the first task in the queue
    int tail;                  // Index of the next available slot in the queue
    int stop;                  // Flag to indicate if the pool is stopping
    int thread_count;          // Number of threads in the pool
} ThreadPool;

// Worker thread function to process tasks
void *worker_thread(void *arg) {
    ThreadPool *pool = (ThreadPool *)arg;

    while (1) {
        pthread_mutex_lock(&pool->lock);

        // Wait for tasks to be available or for the pool to stop
        while (pool->queue_size == 0 && !pool->stop) {
            pthread_cond_wait(&pool->cond, &pool->lock);
        }

        // Exit if the pool is stopping
        if (pool->stop) {
            pthread_mutex_unlock(&pool->lock);
            break;
        }

        // Fetch the next task from the queue
        Task task = pool->task_queue[pool->head];
        pool->head = (pool->head + 1) % pool->queue_capacity;
        pool->queue_size--;

        pthread_mutex_unlock(&pool->lock);

        // Execute the task
        task.function(task.arg);
    }

    return NULL;
}

// Create and initialize a thread pool
ThreadPool *thread_pool_create(int thread_count, int queue_capacity) {
    ThreadPool *pool = (ThreadPool *)malloc(sizeof(ThreadPool));
    pool->thread_count = thread_count;
    pool->queue_capacity = queue_capacity;
    pool->queue_size = 0;
    pool->head = 0;
    pool->tail = 0;
    pool->stop = 0;

    pool->threads = (pthread_t *)malloc(sizeof(pthread_t) * thread_count);
    pool->task_queue = (Task *)malloc(sizeof(Task) * queue_capacity);

    pthread_mutex_init(&pool->lock, NULL);
    pthread_cond_init(&pool->cond, NULL);

    for (int i = 0; i < thread_count; i++) {
        pthread_create(&pool->threads[i], NULL, worker_thread, pool);
    }

    return pool;
}

// Add a task to the thread pool
void thread_pool_add_task(ThreadPool *pool, void (*function)(void *), void *arg) {
    pthread_mutex_lock(&pool->lock);

    // Add the task to the queue
    pool->task_queue[pool->tail].function = function;
    pool->task_queue[pool->tail].arg = arg;
    pool->tail = (pool->tail + 1) % pool->queue_capacity;
    pool->queue_size++;

    // Signal a worker thread that a task is available
    pthread_cond_signal(&pool->cond);
    pthread_mutex_unlock(&pool->lock);
}

// Destroy the thread pool and clean up resources
void thread_pool_destroy(ThreadPool *pool) {
    pthread_mutex_lock(&pool->lock);
    pool->stop = 1; // Set the stop flag
    pthread_cond_broadcast(&pool->cond); // Wake up all worker threads
    pthread_mutex_unlock(&pool->lock);

    // Join all worker threads
    for (int i = 0; i < pool->thread_count; i++) {
        pthread_join(pool->threads[i], NULL);
    }

    // Free allocated resources
    free(pool->threads);
    free(pool->task_queue);
    pthread_mutex_destroy(&pool->lock);
    pthread_cond_destroy(&pool->cond);
    free(pool);
}

// Example task function
void example_task(void *arg) {
    int num = *(int *)arg;
    printf("Task %d is running\n", num);
    sleep(1); // Simulate work
}

// Main function to demonstrate the thread pool
int main() {
    ThreadPool *pool = thread_pool_create(4, 10); // Create a thread pool with 4 threads and a queue capacity of 10

    // Add 20 tasks to the thread pool
    for (int i = 0; i < 20; i++) {
        int *arg = (int *)malloc(sizeof(int));
        *arg = i;
        thread_pool_add_task(pool, example_task, arg);
    }

    sleep(5); // Allow tasks to complete
    thread_pool_destroy(pool); // Destroy the thread pool

    return 0;
}
