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
#define INF 2147483648
typedef long long ll;

int N, K;
int dp[1001][10001];
int I[1001], T[1001];

int solve(void)
{
    for (int i = 1; i <= K; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (T[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - T[i]] + I[i]);
        }
    }
    return dp[K][N];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= K; i++)
        cin >> I[i] >> T[i];
    cout << solve() << "\n";
    return 0;
}
