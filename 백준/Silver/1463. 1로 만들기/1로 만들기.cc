#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int dp[1000001] = { 0,0,1,1 };

int main(void) {
	scanf("%d", &N);
	if (N >= 4) {
		for (int i = 4; i <= N; i++) {
			dp[i] = dp[i - 1] + 1;  //1빼기 연산
			if (i % 3 == 0)
				dp[i] = min(dp[i / 3] + 1, dp[i]);
			if (i % 2 == 0)
				dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
	}
	printf("%d", dp[N]);
	return 0;
}