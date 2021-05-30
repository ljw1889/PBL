#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6
int sorted[MAX_SIZE];
void merge(int list[], int left, int mid, int right) {  //입력받은 숫자를 나눈다
	int i, j, k, l; i = left; j = mid + 1; k = left;
	//분할된 리스트를 다시 합병한다
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid) //남아있는 레코드 일괄 복사
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)//남아있는 레코드 일괄 복사
			sorted[k++] = list[l];
	//배열sorted[]의 리스트를 배열 list[]로 복사
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) { //입력받은 숫자들의 수열을 다시 합친다.
	int mid;
	if (left < right) {
		mid = (left + right) / 2; //리스트 분할
		merge_sort(list, left, mid); //부분리스트 정렬
		merge_sort(list, mid + 1, right);//부분리스트 정렬
		merge(list, left, mid, right); //합병
	}
}
int main() {
	int N = 0;
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	merge_sort(arr, 0, N - 1);
	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
	free(arr);
	return 0;
}