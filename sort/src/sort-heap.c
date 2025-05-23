/**
 * @file sort-head.c
 * @brief heap sort
 */
#include <stdio.h>

/* 堆的长度为 n ，从节点 i 开始，从顶至底堆化 */
void siftDown(int nums[], int n, int i) {
  while (1) {
    /* 判断节点 i, l, r 中值最大的节点，记为 ma */
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int ma = i;
    if (l < n && nums[l] > nums[ma])
      ma = l;
    if (r < n && nums[r] > nums[ma])
      ma = r;
    /* 若节点 i 最大或索引 l, r 越界，则无须继续堆化，跳出 */
    if (ma == i) {
      break;
    }
    /* 交换两节点 */
    int temp = nums[i];
    nums[i] = nums[ma];
    nums[ma] = temp;
    /* 循环向下堆化 */
    i = ma;
  }
}

/* 堆排序 */
void heapSort(int nums[], int n) {
  // 建堆操作：堆化除叶节点以外的其他所有节点
  for (int i = n / 2 - 1; i >= 0; --i) {
    siftDown(nums, n, i);
  }
  // 从堆中提取最大元素，循环 n-1 轮
  for (int i = n - 1; i > 0; --i) {
    // 交换根节点与最右叶节点（交换首元素与尾元素）
    int tmp = nums[0];
    nums[0] = nums[i];
    nums[i] = tmp;
    // 以根节点为起点，从顶至底进行堆化
    siftDown(nums, i, 0);
  }
}

int main() {
  int nums[10] = {1, 0, 2, 3, 6, 5, 8, 7, 9, 4};
  heapSort(nums, 10);
  for (int i = 0; i < 10; ++i) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}