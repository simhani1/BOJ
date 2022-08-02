#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int arr[500][500];

int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			arr[i - 1][j] = max(arr[i - 1][j] + arr[i][j], arr[i - 1][j] + arr[i][j + 1]);
		}
	}
	printf("%d", arr[0][0]);
	return 0;
}