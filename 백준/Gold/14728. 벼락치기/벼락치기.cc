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

int N, T;
int K[101], S[101];
int dp[101][10001];

void solve(void)
{
    for (int lecture = 1; lecture <= N; lecture++)
    {
        for (int t = 0; t <= T; t++)
        {
            if (K[lecture] <= t)
                dp[lecture][t] = max(dp[lecture - 1][t], dp[lecture - 1][t - K[lecture]] + S[lecture]);
            else
                dp[lecture][t] = dp[lecture - 1][t];
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> T;
    for (int i = 1; i <= N; i++)
    {
        cin >> K[i] >> S[i];
    }
    solve();
    cout << dp[N][T];
    return 0;
}
