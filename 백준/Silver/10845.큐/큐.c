#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int arr_queue[10000];
int front = 0;
int rear = 0;

void queue_push(int);
void queue_pop();
void queue_size();
void queue_empty();
void queue_front();
void queue_back();

void queue_push(int x) {
	arr_queue[rear] = x;
	rear++;
}

void queue_pop(void) {
	if (front == rear)  //큐가 비어있을 경우
		printf("%d\n", -1);
	else {
		printf("%d\n", arr_queue[front]);
		front++;
	}
}

void queue_size(void) {
	printf("%d\n", rear - front);
}

void queue_empty(void) {
	if (front == rear)
		printf("%d\n", 1);
	else		
		printf("%d\n", 0);
}

void queue_front(void) {
	if (front == rear)
		printf("%d\n", -1);
	else
		printf("%d\n", arr_queue[front]);
}

void queue_back(void) {
	if (front == rear)
		printf("%d\n", -1);
	else
		printf("%d\n", arr_queue[rear-1]);
}

int main(void) {
	int N, num, i;
	char str[5] = {0};  //명령 최대 길이==5

	scanf("%d", &N);  //명령의 개수 입력받기
	
	for (i = 0; i < N; i++) { 
		scanf("%s", str);  //명령 입력받기 

		if (!(strcmp("push", str))) {
			scanf("%d", &num);
			queue_push(num);
		}
		else if (!(strcmp("pop", str)))
			queue_pop();
		else if (!(strcmp("size", str)))
			queue_size();
		else if (!(strcmp("empty", str)))
			queue_empty();
		else if (!(strcmp("front", str)))
			queue_front();
		else if (!(strcmp("back", str)))
			queue_back();
	}
	return 0;
}