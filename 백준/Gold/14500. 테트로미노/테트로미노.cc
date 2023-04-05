#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
#define INF 123456789
typedef long long ll;

int N, M, ans = 0;
int arr[501][501];
bool visited[501][501];
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int sum, int idx)
{
    if (idx == 4)
    {
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M && !visited[nextX][nextY])
        {
            visited[nextX][nextY] = true;
            dfs(nextX, nextY, sum + arr[nextX][nextY], idx + 1);
            visited[nextX][nextY] = false;
        }
    }
}

void shape1(int x, int y)
{
    if (0 <= x - 1 && x - 1 < N && 0 <= y + 1 && 0 <= y + 2 && y + 2 < M)
    {
        int sum = arr[x][y] + arr[x][y + 1] + arr[x - 1][y + 1] + arr[x][y + 2];
        ans = max(ans, sum);
    }
}

void shape2(int x, int y)
{
    if (0 <= x + 1 && x + 2 < N && 0 <= y + 1 && y + 1 < M)
    {
        int sum = arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x + 1][y + 1];
        ans = max(ans, sum);
    }
}

void shape3(int x, int y)
{
    if (0 <= x + 1 && x + 1 < N && 0 <= y + 1 && y + 2 < M)
    {
        int sum = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x + 1][y + 1];
        ans = max(ans, sum);
    }
}

void shape4(int x, int y)
{
    if (0 <= x - 1 && x + 1 < N && 0 <= y + 1 && y + 1 < M)
    {
        int sum = arr[x][y] + arr[x - 1][y + 1] + arr[x][y + 1] + arr[x + 1][y + 1];
        ans = max(ans, sum);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = true;
            dfs(i, j, arr[i][j], 1);
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            shape1(i, j);
            shape2(i, j);
            shape3(i, j);
            shape4(i, j);
        }
    }
    cout << ans << "\n";
    return 0;
}
