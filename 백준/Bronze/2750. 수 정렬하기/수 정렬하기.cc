#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int* p;
	int N, i;
	
	scanf("%d", &N);
	p = (int*)malloc(sizeof(int)*N);

	for (i = 0; i < N; i++) {
		scanf("%d", p + i);
	}
	sort(p, p + N);

	for (i = 0; i < N; i++) {
		printf("%d\n", p[i]);
	}

	delete[] p;
	return 0;
}