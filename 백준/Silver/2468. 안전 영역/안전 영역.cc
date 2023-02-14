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

int N, maxHeight = 0, ans = 1; // 최초의 상태는 한  덩어리
int arr[101][101], dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
bool visited[101][101];

void dfs(int x, int y, int target)
{
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (!visited[nextX][nextY])
        {
            if (0 <= nextX && nextX < N && 0 <= nextY && nextY < N)
            {
                if (arr[nextX][nextY] > target)
                    dfs(nextX, nextY, target);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            maxHeight = max(maxHeight, arr[i][j]);
        }
    }
    for (int k = 1; k <= maxHeight; k++)
    {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            fill(visited[i], visited[i] + N, false);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[i][j] > k && !visited[i][j])
                {
                    dfs(i, j, k);
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}
