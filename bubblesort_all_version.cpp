#include <stdio.h>
#define N 5

// 配列を表示させる関数
void print_arr(int arr[], int cnt) {
  for (int i = 0; i < N; i++) {
    printf("%d ", arr[i]);
  }

  // カウンタ変数を表示させるか
  if (cnt != -1) {
    printf("(i = %d)\n", cnt);
  } else {
    printf("\n");
  }
}

int main(void) {
  int sort[N] = {2, 3, 1, 5, 4};
  int tmp; // tmp: 値を一時的に格納する
  int largest_num_index[2] = {0, 1};
  bool flag = false; // 値の交換が行われたかを判断する
  int comp_index = N;

  printf("ソート前: ");

  // 第二引数が-1の時はiの表示を行わない
  print_arr(sort, -1);
  do {
    flag = false;
    for (int i = 0; i < comp_index - 1; i++) {
      if (sort[i] > sort[i + 1]) {
        flag = true;
        tmp = sort[i];
        sort[i] = sort[i + 1];
        sort[i + 1] = tmp;
      }
      // 2番目に小さい値
      if (sort[i] > sort[largest_num_index[0]]) {
        largest_num_index[0] = i;
      }
      // 1番小さい値
      if (sort[i + 1] > sort[largest_num_index[1]]) {
        largest_num_index[1] = i + 1;
      }

      // 配列を表示、カウンタ変数を第二引数に指定
      print_arr(sort, i);
    }
    if (sort[comp_index - 2] == sort[largest_num_index[0]] &&
        sort[comp_index - 1] == sort[largest_num_index[1]]) {
      comp_index -= 2;
    } else if (sort[comp_index - 1] == sort[largest_num_index[1]]) {
      comp_index -= 1;
    }
    largest_num_index[0] = 0;
    largest_num_index[1] = 1;
  } while (flag);
  printf("ソート終了\n");

  printf("ソート後: ");

  // 第二引数が-1の時はiの表示を行わない
  print_arr(sort, -1);

  return 0;
}
