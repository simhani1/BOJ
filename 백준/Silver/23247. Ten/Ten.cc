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

int M, N, ans = 0;
int arr[301][301], sum[301][301];

void solve(int x, int y)
{
    for (int i = x; i <= M; i++)
    {
        for (int j = y; j <= N; j++)
        {
            int tmp = sum[i][j] - sum[i][y - 1] - sum[x - 1][j] + sum[x - 1][y - 1];
            if (tmp >= 10)
            {
                if (tmp == 10)
                    ans++;
                break;
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
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
        }
    }
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            solve(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}
