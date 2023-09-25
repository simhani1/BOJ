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
int arr[55][55];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int visited[55][55];
bool flag;

void input(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            arr[i][j] = str[j] - 'A';
        }
    }
}

void dfs(int nowX, int nowY, int sX, int sY, int cnt)
{
    visited[nowX][nowY] = cnt;
    for (int i = 0; i < 4; i++)
    {
        int nextX = nowX + dx[i];
        int nextY = nowY + dy[i];
        if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M)
        {
            if (!visited[nextX][nextY] && arr[nextX][nextY] == arr[nowX][nowY])
                dfs(nextX, nextY, sX, sY, cnt + 1);
            // 방문 시간이 3이상 차이나야 사이클
            else if (visited[nextX][nextY] - cnt >= 3 && arr[nextX][nextY] == arr[nowX][nowY])
            {
                flag = true;
                return;
            }
        }
    }
}

void solve(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j])
                dfs(i, j, i, j, 1);
        }
    }
    flag ? cout << "Yes\n" : cout << "No\n";
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
