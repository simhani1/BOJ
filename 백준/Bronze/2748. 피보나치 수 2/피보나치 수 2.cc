#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long ans[100];

int main(void) {
	long long result, N;
	scanf("%lld", &N);
	ans[0] = 0;
	ans[1] = 1;
	for (int i = 2; i <= N; i++) {
		ans[i] = ans[i - 1] + ans[i - 2];
	}
	printf("%lld", ans[N]);
	return 0;
}