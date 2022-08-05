#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int calender[15][2];
int dp[15];

int revenue(int n) {
	if (n > N)
		return -1234;
	else if (n == N)
		return 0;
	if (dp[n] != -1)
		return dp[n];
	else {
		dp[n] = max(revenue(n + 1), revenue(n + calender[n][0]) + calender[n][1]);
		return dp[n];
	}
}

int main(void) {
	int T, P;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &T, &P);
		calender[i][0] = T;
		calender[i][1] = P;
		dp[i] = -1;
	}
	printf("%d", revenue(0));
	return 0;
}