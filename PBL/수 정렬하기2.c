#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6
int sorted[MAX_SIZE];
void merge(int list[], int left, int mid, int right) {  //�Է¹��� ���ڸ� ������
	int i, j, k, l; i = left; j = mid + 1; k = left;
	//���ҵ� ����Ʈ�� �ٽ� �պ��Ѵ�
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid) //�����ִ� ���ڵ� �ϰ� ����
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)//�����ִ� ���ڵ� �ϰ� ����
			sorted[k++] = list[l];
	//�迭sorted[]�� ����Ʈ�� �迭 list[]�� ����
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) { //�Է¹��� ���ڵ��� ������ �ٽ� ��ģ��.
	int mid;
	if (left < right) {
		mid = (left + right) / 2; //����Ʈ ����
		merge_sort(list, left, mid); //�κи���Ʈ ����
		merge_sort(list, mid + 1, right);//�κи���Ʈ ����
		merge(list, left, mid, right); //�պ�
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