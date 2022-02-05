#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int T, N;
int dp[11] = {0,1,2,4 };

int main(void) {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		if (N < 4)
			printf("%d\n", dp[N]);
		else {
			for (int j = 4; j <= N; j++) {
				dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
			}
			printf("%d\n", dp[N]);
		}
	}
	return 0;
}