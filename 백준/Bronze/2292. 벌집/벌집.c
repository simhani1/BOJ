#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void) {
	int sum = 0;
	int cnt = 0;
	int N;
	scanf("%d", &N);
	if (N == 1) {
		printf("%d", cnt + 1);
		return 0;
	}
	while (N > sum) {
		sum += cnt++ * 6;
		if (sum + 1 == N) {
			printf("%d\n", cnt);
			return 0;
	}
	}
	printf("%d\n", cnt);
	return 0;
}