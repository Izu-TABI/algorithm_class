#include <cstdio>
#define N 10
#include <stdio.h>

int main() {
  int array[N] = {12, 15, 33, 39, 51, 64, 77, 79, 81, 100};
  int a, left, mid, right;

  printf("何を探しますか？: ");
  scanf("%d", &a);
  left = 0;
  right = N - 1;

  while (1) {
    mid = (left + right) / 2;
    if (mid < left || mid > right) {
      printf("値は配列の中にありません。\n");
      break;
    }
    if (a == array[mid]) {
      printf("値は%dにあります。", mid);
      break;
    } else if (a > array[mid]) {
      left = mid + 1;
    } else if (a < array[mid]) {
      right = mid - 1;
    }
    printf("mid: %d\nleft: %d\nright: %d\n\n", mid, left, right);
  }

  return 0;
}
