#include <stdio.h>
#define N 10 // Nはデータ数

void QuickSort(int data[], int left,
               int right) // voidは型がなく配列を共有するので戻り値がない
// data[]は配列名(アドレスを)受け取る=配列の共有
// leftはグループ左位置(要素番号)を受け取る rightはグループの右位置を受け取る
{
  int pivot; // pivot:軸
  int i, j, k, tmp;
  if (left >= right) {
    // ソートの範囲が1以下の場合個別ループとなり、ソートが終わる
    return;
    // 関数の出口
  }
  pivot = data[left];
  // 1番左のデータをpivot(軸)
  i = left;
  j = right;
  // left rightの値をi,jに保存しi,jを操作することで値を壊さないようにする
  while (1) {
    while (data[i] < pivot) {
      i++; // dataがpivotより小さい間増やす　
      // pivot以上になるとループを終了させる、pivotより大きい位置で止まるこの位置を左から探している　
    }
    while (data[j] > pivot) {
      j--;
      　 //pivot以下の数字を右から探す
    }
    if (i >= j) {
      break;
      　 //while(1)は無限ループなので出口
    }
    tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
    　 //交換のプロセス
        for (k = 0; k < N; k++) {
      printf("%d ", data[k]);
    }
    printf("(pivot = %d にて入れ替えた)\n", pivot);
    　 //途中結果の出力
        i++;
    j--;
    　 //内側に入る
  }
  QuickSort(data, left, i - 1);
  　 //左側のグループについて同様の処理を行う
      QuickSort(data, j + 1, right);
  　  //右側のグループについて同様の処理を行う
      // 再起呼出(recursive
  // call)　どんどん内側に入りグループを分けるこの右側グループと左側グループでソートを繰り返す
}
int main(void) {
  int sort[N] = {5, 0, 9, 7, 1, 6, 3, 8, 4, 2};
  int i;
  printf("ソート前:");
  for (i = 0; i < N; i++) {
    printf("%d ", sort[i]);
  }
  printf("\n");
  printf("\nソート開始\n");
  printf("\n");

  QuickSort(sort, 0, N - 1);

  printf("\nソート終了\n");
  printf("\nソート後:");
  for (i = 0; i < N; i++) {
    printf("%d ", sort[i]);
  }
  return 0;
}
