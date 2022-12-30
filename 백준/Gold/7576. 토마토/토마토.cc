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
#define MAX 9223372036854775807
typedef long long ll;

int N, M, cnt = 0;
int arr[1001][1001];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
queue<pair<int, int>> q;

void bfs(void)
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny <= M)
            {
                if (arr[nx][ny] == 0)
                {
                    arr[nx][ny] = arr[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                q.push({i, j});
        }
    }
    bfs();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
            {
                cout << -1 << "\n";
                return 0;
            }
            cnt = max(cnt, arr[i][j]);
        }
    }
    cout << cnt - 1 << "\n";
    return 0;
}
