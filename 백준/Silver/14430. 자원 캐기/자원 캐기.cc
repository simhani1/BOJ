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
int arr[301][301], dp[301][301];

void input(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void solve(void)
{
    dp[0][0] = arr[0][0];
    for (int i = 1; i < N; i++)
    {
        dp[i][0] += (dp[i - 1][0] + arr[i][0]);
    }
    for (int i = 1; i < M; i++)
    {
        dp[0][i] += (dp[0][i - 1] + arr[0][i]);
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
        }
    }
    cout << dp[N - 1][M - 1] << "\n";
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
