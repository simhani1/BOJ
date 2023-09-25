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
int sX, sY, gX, gY;
int arr[305][305];
bool visited[305][305];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
queue<pair<int, int>> q;

void input(void)
{
    cin >> N >> M;
    cin >> sX >> sY >> gX >> gY;
    sX--;
    sY--;
    gX--;
    gY--;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }
}

void init(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
        }
    }
}

void dfs(int nowX, int nowY)
{
    visited[nowX][nowY] = true;
    if (nowX == gX && nowY == gY)
        return;
    for (int i = 0; i < 4; i++)
    {
        int nextX = nowX + dx[i];
        int nextY = nowY + dy[i];
        if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M)
        {
            if (visited[nextX][nextY])
                continue;
            if (arr[nextX][nextY] == 1)
                q.push({nextX, nextY});
            else
                dfs(nextX, nextY);
        }
    }
}

void solve(void)
{
    int ans = 0;
    while (true)
    {
        init();
        dfs(sX, sY);
        while (!q.empty())
        {
            arr[q.front().first][q.front().second] = 0;
            q.pop();
        }
        ans++;
        if (visited[gX][gY])
            break;
    }
    cout << ans << "\n";
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
