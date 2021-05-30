#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort_string(char* list[], int size) {//버블 정렬을 사용하여 정렬
	int least;
	char* temp;

	for (int i = 0; i < size - 1; i++) {
		least = i;	//i 번째 값을 최소값으로 가정
		for (int j = i + 1; j < size; j++) {	//최소값 탐색
			if (strcmp(list[j], list[least]) < 0) {
				least = j;
			}
		}
		temp = list[i];
		list[i] = list[least];
		list[least] = temp;
	}
}

void main() {
	char* s[100];	//포인터 배열 사용.
	s[0] = "mycopy";
	s[1] = "src";
	s[2] = "dst";
	for (int i = 0; i < 3; i++) {
		printf("%s ", s[i]);
	}
	printf("\n");
	sort_string(s, 3);
	for (int i = 0; i < 3; i++) {
		printf("%s ", s[i]);
	}
}
