#include<stdio.h>
#include<stdlib.h>
int arr[100001], count = 0;	// 배열을 전역 변수로 사용, count는 배열의 요소의 개수를 컨트롤 하기 위함.

void push(int item) {
	arr[count] = item;
	count++;      //아이템을 넣으면, count 가 1 증가.
}

void pop() {
	int max = arr[0];  //최대값을 배열의 처음 값으로 놓고 반복문을 사용하여, 최대값 탐색
	for (int i = 0; i < count; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	printf("%d\n", max); //최대값 출력

	for (int i = 0; i < count; i++) {
		if (max == arr[i]) {  //배열에서 최대값과 같은 인덱스가 있다면, 그 배열의 요소는 0 으로 할당.
			arr[i] = 0;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int a;
	while (n--) {
		scanf("%d", &a);
		if (a == 0) { // 입력 수가 0 이라면 pop
			if (count == 0) {
				printf("0\n"); //배열이 비었을 때, 0으로 출력되게 함.
				continue;
			}
			pop();
		}
		if (a != 0) { // 입력 수가 0 이 아닌 자연수 라면 push
			push(a);
		}
	}
	return 0;
}