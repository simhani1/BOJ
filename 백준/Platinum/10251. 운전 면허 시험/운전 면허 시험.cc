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
#include <sstream>
#include <cmath>
using namespace std;
#define INF 123456789
#define MOD 1000000
typedef long long ll;

int T;
int M, N, L, G;
int rd[101][101], dd[101][101];
int dp[101][101][2][205];

void init(void)
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            rd[i][j] = 0;
            dd[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 205; l++)
                {
                    dp[i][j][k][l] = INF;
                }
            }
        }
    }
}

void solve(void)
{
    // 초기화
    dp[0][0][0][0] = dp[0][0][1][0] = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int turn = 0; turn < N + M; turn++)
            {
                if (j + 1 < N)
                {
                    dp[i][j + 1][0][turn + 1] = min(dp[i][j + 1][0][turn + 1], dp[i][j][1][turn] + rd[i][j]);
                    dp[i][j + 1][0][turn] = min(dp[i][j + 1][0][turn], dp[i][j][0][turn] + rd[i][j]);
                }
                if (i + 1 < M)
                {
                    dp[i + 1][j][1][turn + 1] = min(dp[i + 1][j][1][turn + 1], dp[i][j][0][turn] + dd[i][j]);
                    dp[i + 1][j][1][turn] = min(dp[i + 1][j][1][turn], dp[i][j][1][turn] + dd[i][j]);
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < N + M; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (dp[M - 1][N - 1][j][i] <= G)
                ans = min(ans, (M + N - 2) * L + i);
        }
    }
    ans == INF ? cout << -1 << "\n" : cout << ans << "\n";
}

void input(void)
{
    cin >> T;
    while (T--)
    {
        init();
        cin >> M >> N >> L >> G;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N - 1; j++)
            {
                cin >> rd[i][j];
            }
        }
        for (int i = 0; i < M - 1; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> dd[i][j];
            }
        }
        solve();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    return 0;
}
