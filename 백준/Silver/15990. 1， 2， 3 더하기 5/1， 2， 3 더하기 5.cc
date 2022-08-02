#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <map>
#include <set>
using namespace std;
#define MOD 1000000009

int T, N;
long long dp[100001][4] = {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 1, 1, 1}}; // base case

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // i를 1로 시작하는 합, 2로 시작하는 합, 3으로 시작하는 합의 수를 저장
    // 1로 시작한다면 i-1을 2, 3으로 시작하는 합의 수와 동일
    // 2로 시작한다면 i-2를 1, 3으로 시작하는 합의 수와 동일
    // 3으로 시작한다면 i-3을 1, 2로 시작하는 합의 수와 동일
    for (int i = 4; i <= 100000; i++)
    {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
    }
    cin >> T;
    while (T--)
    {
        cin >> N;
        // 최종적으로 N을 나타내는 방법은 1, 2, 3으로 시작하는 합의 수의 총합
        // 각각 최대 MOD의 값을 가질 수 있으므로 3개를 더하게 되면 int의 범위를 벗어남
        cout << (dp[N][1] + dp[N][2] + dp[N][3]) % MOD << endl;
    }
    return 0;
}
