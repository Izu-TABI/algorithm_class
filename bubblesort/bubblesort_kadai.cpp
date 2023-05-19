#include <stdio.h>
#define N 5 // Nはデータ数
int main(void) {
  int sort[N] = {2, 3, 1, 5, 4};
  int comp_index = N;
  int i, j, k,
      frag; // i,jはカウンター。hは交換用の逃がし。fragは交換の「あり」「なし」frag:1
            // 交換あり :0 交換無し
  printf("ソート前:");
  for (i = 0; i < N; i++) {
    printf("%d ", sort[i]);
  }
  printf("\n"); // 配列ソートの出力
  printf("\nソート開始\n");
  do {
    frag = 0;                              // 右まで行ったら0に戻す
    for (i = 0; i < comp_index - 1; i++) { // sort[4]=N-1 ラストの位置に注意
      if (sort[i] > sort[i + 1]) {
        frag = 1; // 変更ありなのでフラグを立てる
        j = sort[i];
        sort[i] = sort[i + 1];
        sort[i + 1] = j; // 交換のプロセス
        if (sort[i] == i + 1 && sort[i + 1] == i + 2) {
          comp_index -= 2;
        }
      }
      for (k = 0; k < N; k++) {
        printf("%d ", sort[k]);
      }
      printf(
          "(i=%d)\n",
          i); // 配列sortの出力（iを壊さないようにカウンタkを使用）そのときのiを出力
    }
  } while (
      frag ==
      1); // fragが1の間繰り返す。つまりfrag=0で終了。frag=0は交換が1度と行われないことを示す。
  printf("ソート終了\n");
  printf("\nソート後:");
  for (i = 0; i < N; i++) {
    printf("%d ", sort[i]);
  }
  printf("\n");
  return 0;
}
