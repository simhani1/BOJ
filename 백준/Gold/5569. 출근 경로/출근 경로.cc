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

int W, H;
int dp[101][101][4];

void input(void)
{
    cin >> W >> H;
}

void solve(void)
{
    for (int i = 1; i <= W; i++)
    {
        dp[i][1][1] = 1;
    }
    for (int i = 1; i <= H; i++)
    {
        dp[1][i][2] = 1;
    }
    int ans = 0;
    for (int i = 2; i <= W; i++)
    {
        for (int j = 2; j <= H; j++)
        {
            dp[i][j][0] = dp[i][j - 1][1];
            dp[i][j][1] = (dp[i - 1][j][1] + dp[i - 1][j][3]) % 100000;
            dp[i][j][2] = (dp[i][j - 1][0] + dp[i][j - 1][2]) % 100000;
            dp[i][j][3] = dp[i - 1][j][2];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        ans = (ans + dp[W][H][i]) % 100000;
    }
    cout << ans << endl;
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
