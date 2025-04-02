#include <stdio.h>
#include <stdlib.h>

#define EMPTY_VALUE -1

/**
 * @brief init array
 *
 * @details 初始化数组为空值，这里设定数组的空值是-1
 *
 * @param 数组长度len
 *
 * @return 返回值：初始化空值之后的数组
 */
int *init_array(int len) {
  int *arr = (int *)malloc(len * sizeof(int));
  for (int i = 0; i < len; i++) {
    arr[i] = EMPTY_VALUE;
  }
  return arr;
}

/**
 * @brief array insert element
 *
 * @param 数组arr、要插入的元素val、位置ind前插入元素、数组长度len
 *
 * @return 返回值：成功0；失败-1；
 */
int insert_element(int arr[], int val, int ind, int len) {
  if (arr[len - 1] != EMPTY_VALUE) {
    return -1;
  }
  /*move back*/
  for (int i = len - 1; i > ind; i--) {
    arr[i] = arr[i - 1];
  }
  /*insert element*/
  arr[ind] = val;
  return 0;
}

/**
 * @brief delete element
 *
 * @param 数组arr、要删除的元素下标ind、数组长度len
 *
 * @return 返回值：成功0；失败-1；
 */
int delete_element(int arr[], int ind, int len) {
  if (arr[ind] == EMPTY_VALUE) {
    return -1;
  }
  /*move force*/
  for (int i = ind; i < len - 1; i++) {
    arr[i] = arr[i + 1];
  }
  arr[len - 1] = EMPTY_VALUE;
  return 0;
}

/**
 * @brief traverse arr and printf
 *
 * @param 数组arr,数组长度len
 */
void traverse_array(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d\t", arr[i]);
    if ((i + 1) % 5 == 0) {
      printf("\n");
    }
  }
  printf("\n");
}

/**
 * @brief search element
 *
 * @param 数组arr、要查找的元素的值val、数组长度len
 *
 */
void search_element(int arr[], int val, int len) {
  for (int i = 0; i < len; i++) {
    if (arr[i] == val) {
      printf("%d\t\t", i);
    }
  }
}

/**
 * @brief extend array
 *
 * @param 数组arr，数组长度len,拓展后的长度ext
 *
 * @return 返回值：成功返回拓展之后的数组，失败返回NULL;
 */
int *extend_array(int arr[], int len, int ext) {
  int *extend = (int *)malloc(ext * sizeof(int));
  if (extend == NULL) {
    return NULL;
  }
  for (int i = 0; i < len; i++) {
    extend[i] = arr[i];
  }

  for (int i = len; i < ext; i++) {
    extend[i] = EMPTY_VALUE;
  }

  return extend;
}

/**
 * @brief modify element
 *
 * @param 数组arr,元素下标ind,要修改成的值val
 *
 */
void modify_element(int arr[], int ind, int val) { arr[ind] = val; }

int main(int argc, char **argv) {
  int len = 10;
  int exlen = 20;
  int *b = init_array(len);
  for (int i = 0; i < len; i++) {
    b[i] = i;
  }
  insert_element(b, 99, 1, len);
  traverse_array(b, len);
  int *c = extend_array(b, len, exlen);
  traverse_array(c, exlen);
  free(b);
  free(c);
  return 0;
}