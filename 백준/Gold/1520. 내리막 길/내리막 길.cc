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

int N, M;
int arr[501][501], dp[501][501];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void input(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
}

int dfs(int nowX, int nowY, int prev)
{
    if (dp[nowX][nowY] != -1)
        return dp[nowX][nowY];
    if (nowX == N - 1 && nowY == M - 1)
        return 1;
    dp[nowX][nowY] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nextX = nowX + dx[i];
        int nextY = nowY + dy[i];
        if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
            continue;
        if (arr[nextX][nextY] >= prev)
            continue;
        dp[nowX][nowY] += dfs(nextX, nextY, arr[nextX][nextY]);
    }
    return dp[nowX][nowY];
}

void solve(void)
{
    cout << dfs(0, 0, arr[0][0]) << "\n";
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
