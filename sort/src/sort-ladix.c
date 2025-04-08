#include <stdio.h>
#include <stdlib.h>

/* Function to get the maximum value in an array */
int getMax(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

/* Function to perform counting sort based on a specific digit */
void countingSort(int arr[], int n, int exp) {
  int *output = (int *)malloc(n * sizeof(int));
  int count[10] = {0};

  /* Count occurrences of each digit */
  for (int i = 0; i < n; i++) {
    count[(arr[i] / exp) % 10]++;
  }

  /* Update count[i] to store the position of the digit in output[] */
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  /* Build the output array */
  for (int i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  /* Copy the output array back to arr[] */
  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }

  free(output);
}

/* Radix Sort function */
void radixSort(int arr[], int n) {
  int max = getMax(arr, n);

  /* Perform counting sort for each digit */
  for (int exp = 1; max / exp > 0; exp *= 10) {
    countingSort(arr, n, exp);
  }
}

/* Function to print an array */
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

/* Main function to test Radix Sort */
int main() {
  int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array:\n");
  printArray(arr, n);

  radixSort(arr, n);

  printf("Sorted array:\n");
  printArray(arr, n);

  return 0;
}
