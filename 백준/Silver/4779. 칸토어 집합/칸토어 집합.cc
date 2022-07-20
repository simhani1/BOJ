#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

char arr[531441];

void cantor(int size, int start, int end) {
	size /= 3;
	if (size == 0) {
		return;
	}
	for (int i = start; i < end; i++) {
		arr[i] = ' ';
	}
	cantor(size, start - size / 3 * 2, start - size / 3);
	cantor(size, end + size / 3, end + size / 3 * 2);

	return;
}

int main(void) {
	int N, size = 1;
	while (scanf("%d", &N) != EOF) {
		size = pow(3, N);
		for (int i = 0; i < size; i++) {
			arr[i] = '-';
		}
		cantor(size, size / 3, (size / 3) * 2);
		for (int i = 0; i < size; i++) {
			printf("%c", arr[i]);
		}
		printf("\n");
	}
	return 0;
}