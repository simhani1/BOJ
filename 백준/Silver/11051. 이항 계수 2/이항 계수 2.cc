#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, K;
int dp[1001][1001];

int main(void) {
	scanf("%d %d", &N, &K);
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (j == 0 || j == N) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	printf("%d", dp[N][K]);
	return 0;
}