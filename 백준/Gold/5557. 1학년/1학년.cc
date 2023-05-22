#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 123456789
typedef long long ll;

int N, M;
ll arr[101], dp[101][21];

void input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

void solve(void)
{
    dp[0][arr[0]] = 1;
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            ll add = j - arr[i];
            ll sub = j + arr[i];
            if (0 <= add && add <= 20)
                dp[i][j] += dp[i - 1][add];
            if (0 <= sub && sub <= 20)
                dp[i][j] += dp[i - 1][sub];
        }
    }
    cout << dp[N - 2][arr[N - 1]] << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
