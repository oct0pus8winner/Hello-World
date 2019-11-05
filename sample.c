#include <stdio.h>  /*入出力*/
#include <stdlib.h> /*標準ライブラリ*/
#include <string.h> /*文字列*/
#include <math.h>   /*計算*/
#include <assert.h> /*確認*/
#include <ctype.h>  /*文字操作*/

#define N 100
/*第2回課題 1*/

void Sort(int num, int array[], int left, int right);

int Split(int num, int array[], int left, int right);


int main(void)
{
	int num;/*配列の要素数*/
	int array[N] = {0};/*格納する配列*/

	/*入力部*/
  printf("Input the number of elements in the array : ");
  scanf("%d", &num);

	printf("\nInput elements in the array　: ");
	for (size_t i = 0; i < num; i++) {
		scanf("%d", &array[i]);
	}

	//再帰関数での処理
	Sort(num,array, 0, num - 1);

	/*出力部*/
	printf("\nOutput the sorted array\n");
	for (size_t i = 0; i < num; i++) {
		printf("%d ",array[i] );
	}
  return 0;
}


void Sort(int num, int array[], int left, int right)
{
  int center;
  if (right - left > 0) {
    center = Split(num,array,left,right);
    Sort(num,array,left,center);
    Sort(num,array,center+1,right);
  }
}

int Split(int num, int array[], int left, int right)
{
  int temp;
  int boder = left;
  int mid   = array[(left+right)/2];

  for (size_t i = left; i <= right; i++) {
    if (array[i] < mid){
      temp = array[i];
      array[i] = array[boder++];
      array[boder-1] = temp;
    }
  }

  return (boder-1);
}
