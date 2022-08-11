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

int N, K;
int dp[1001][1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    // base case
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    // bottom-up
    // 이항계수의 성질
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
        }
    }
    cout << dp[N][K];
    return 0;
}
