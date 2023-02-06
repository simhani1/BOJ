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

int N;
ll dp[31][31];

ll solve(void)
{
    for (int i = 0; i <= N; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][1];
            else
                dp[i][j] = dp[i - 1][j + 1] + dp[i][j - 1];
        }
    }
    return dp[N][0];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        cin >> N;
        if (N == 0)
            break;
        cout << solve() << "\n";
        for (int i = 0; i <= 30; i++)
            fill(dp[i], dp[i] + 31, 0);
    }
    return 0;
}
