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

int N;
int arr[11][11];
bool visited[11][11];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int ans = 999999;

void plant(int cnt)
{
    if (cnt == 3)
    {
        int tmp = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (visited[i][j])
                    tmp += arr[i][j];
            }
        }
        ans = min(ans, tmp);
        return;
    }
    for (int i = 2; i <= N - 1; i++)
    {
        for (int j = 2; j <= N - 1; j++)
        {
            if (!visited[i][j] && !visited[i - 1][j] && !visited[i + 1][j] && !visited[i][j - 1] && !visited[i][j + 1])
            {
                // 꽃의 범위를 모두 방문체크
                visited[i][j] = true;
                for (int k = 0; k < 4; k++)
                {
                    visited[i + dx[k]][j + dy[k]] = true;
                }
                plant(cnt + 1);
                // 원상 복귀
                visited[i][j] = false;
                for (int k = 0; k < 4; k++)
                {
                    visited[i + dx[k]][j + dy[k]] = false;
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
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }
    plant(0);
    cout << ans;
    return 0;
}