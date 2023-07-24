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
#define INF 2000000000
typedef long long ll;

int N, K, ans = INF;
int arr[21][3], dp[21][4];

void input(void)
{
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        cin >> arr[i][1] >> arr[i][2];
    }
    cin >> K;
}

void init(void)
{
    for (int i = 0; i <= N; i++)
    {
        dp[i][1] = INF;
        dp[i][2] = INF;
    }
}

void dfs(int now, int pSum)
{
    if (now > N)
        return;
    if (now == N)
    {
        ans = min(ans, pSum);
        return;
    }
    dfs(now + 1, pSum + arr[now][1]);
    dfs(now + 2, pSum + arr[now][2]);
}

void solve(void)
{
    dp[1][1] = 0;
    dp[1][2] = 0;
    for (int i = 2; i <= N; i++)
    {
        dp[i][1] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i - 1][1];
        dp[i][2] = min(dp[i - 2][1], dp[i - 2][2]) + arr[i - 2][2];
    }
    ans = min(dp[N][1], dp[N][2]);
    for (int i = 4; i <= N; i++)
    {
        dp[i][3] = min(dp[i - 3][1], dp[i - 3][2]) + K;
        dfs(i, dp[i][3]);
    }
    cout << ans << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    init();
    solve();
    return 0;
}
