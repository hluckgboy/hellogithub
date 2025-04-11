/**
 * @file thread.c
 * @brief thread program
 */
#include <pthread.h>
#include <stdio.h>

static void *thread_func(void *arg) {
  printf("Thread function is running\n");
  return NULL;
}

int main() {
  /* thread id */
  pthread_t thread_id;

  /* thread attribution */
  pthread_attr_t thread_attr;
  pthread_attr_init(&thread_attr);

  /* create thread */
  pthread_create(&thread_id, &thread_attr, thread_func, NULL);

  /* thread exit */
  pthread_join(thread_id, NULL);
  pthread_attr_destroy(&thread_attr);
  pthread_exit(NULL);
  return 0;
}