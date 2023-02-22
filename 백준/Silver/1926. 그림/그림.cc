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
#define INF 2147483648
typedef long long ll;

int N, M;
int arr[501][501];
bool visited[501][501];
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
int ans = 0, cnt = 0;
vector<int> v;

void dfs(int x, int y)
{
    visited[x][y] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M)
        {
            if (!visited[nextX][nextY] && arr[nextX][nextY] == 1)
                dfs(nextX, nextY);
        }
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
            cnt = 0;
            if (!visited[i][j] && arr[i][j] == 1)
            {
                dfs(i, j);
                ans = max(ans, cnt);
                v.push_back(ans);
            }
        }
    }
    cout << v.size() << "\n"
         << ans << "\n";
    return 0;
}
