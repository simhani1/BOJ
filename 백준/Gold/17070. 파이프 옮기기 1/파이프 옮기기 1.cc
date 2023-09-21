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

int N;
int arr[17][17], dp[17][17];

bool checkRight(int x, int y)
{
    return y + 1 <= N && !arr[x][y + 1];
}

bool checkDown(int x, int y)
{
    return x + 1 <= N && !arr[x + 1][y];
}

bool checkAll(int x, int y)
{
    return x + 1 <= N && y + 1 <= N && !arr[x + 1][y + 1] && !arr[x + 1][y] && !arr[x][y + 1];
}

// 직전 방향의 종류 -> 0: 가로 1: 세로 2: 대각선
void dfs(int x, int y, int type)
{
    dp[x][y]++;
    if (type == 0)
    {
        if (checkRight(x, y))
            dfs(x, y + 1, 0);
        if (checkAll(x, y))
            dfs(x + 1, y + 1, 2);
    }
    else if (type == 1)
    {
        if (checkDown(x, y))
            dfs(x + 1, y, 1);
        if (checkAll(x, y))
            dfs(x + 1, y + 1, 2);
    }
    else
    {
        if (checkRight(x, y))
            dfs(x, y + 1, 0);
        if (checkDown(x, y))
            dfs(x + 1, y, 1);
        if (checkAll(x, y))
            dfs(x + 1, y + 1, 2);
    }
}

void solve(void)
{
    dfs(1, 2, 0);
    cout << dp[N][N] << "\n";
}

void input(void)
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
