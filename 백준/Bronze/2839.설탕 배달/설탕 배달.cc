#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;   
    int dp[5000];
    fill_n(dp, 5000, 9999);
    cin >> N;
    dp[3] = 1;
    dp[5] = 1;
    for (int i = 6; i <= N; i++) {
        dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
    }
    if (dp[N] >=9999)
        cout << -1;
    else
        cout << dp[N];
    return 0;
}