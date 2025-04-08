#include <stdio.h>
#include <string.h>
#define MAX 100

/* Function to perform counting sort */
void countingSort(int array[], int size) {
  int output[MAX]; // Output array to store sorted elements
  int count[MAX];  // Count array to store the frequency of each element
  int max = array[0];

  // Find the maximum element in the array
  for (int i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  // Initialize count array with zeros
  memset(count, 0, sizeof(count));

  // Count the occurrences of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Update count array to store cumulative counts
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Build the output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements back to the original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

/* Function to print an array */
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

/* Main function to test counting sort */
int main() {
  int array[] = {4, 2, 2, 8, 3, 3, 1};
  int size = sizeof(array) / sizeof(array[0]);

  printf("Original array:\n");
  printArray(array, size);

  countingSort(array, size);

  printf("Sorted array:\n");
  printArray(array, size);

  return 0;
}
