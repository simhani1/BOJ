#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
#define INF 2147483648
typedef long long ll;

int N, L, R, ans = 0;
int arr[51][51], dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
bool visited[51][51];
bool flag;

void init(void)
{
    flag = false;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q, pos;
    int cnt = 1, sum = 0;
    visited[x][y] = true;
    q.push({x, y});
    while (!q.empty())
    {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();
        pos.push({nowX, nowY});
        sum += arr[nowX][nowY];
        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N && !visited[nextX][nextY])
            {
                int diff = abs(arr[nowX][nowY] - arr[nextX][nextY]);
                if (L <= diff && diff <= R)
                {
                    visited[nextX][nextY] = true;
                    q.push({nextX, nextY});
                    cnt++;
                }
            }
        }
    }
    int population = sum / cnt;
    if (population == sum)
        return;
    else
        flag = true;
    while (!pos.empty())
    {
        arr[pos.front().first][pos.front().second] = population;
        pos.pop();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    while (true)
    {
        flag = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j])
                    bfs(i, j);
            }
        }
        if (flag)
            ans++;
        else
            break;
        init();
    }
    cout << ans << "\n";
    return 0;
}
