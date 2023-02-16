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
#define INF 1234567890
typedef long long ll;

int R, C, ans = 0;
char arr[21][21];
bool visited[26];
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

void dfs(int x, int y, int cnt)
{
    int now = arr[x][y] - 'A';
    if (!visited[now])
    {
        visited[now] = true;
        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (0 <= nextX && nextX < R && 0 <= nextY && nextY < C)
                dfs(nextX, nextY, cnt + 1);
        }
        visited[now] = false;
    }
    ans = max(ans, cnt);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> arr[i];
    dfs(0, 0, 0);
    cout << ans << "\n";
    return 0;
}
