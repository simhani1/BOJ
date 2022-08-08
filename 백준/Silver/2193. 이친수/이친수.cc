#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
long long dp[90] = { 1,1 };

long long pinary_num(int N) {
	if (N - 1 < 2)
		return dp[N - 1];
	else {
		for (int i = 2; i < N; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
	}
	return dp[N - 1];
}
int main(void) {
	scanf("%d", &N);
	printf("%lld", pinary_num(N));
	return 0;
}

//바로 전이 0이라면 0 또는 1추가
//바로 전이 1이라면 0추가
//dp[N]에 n자리 이친수의 개수를 저장
//규칙은 피보나치 수열과 동일함을 발견