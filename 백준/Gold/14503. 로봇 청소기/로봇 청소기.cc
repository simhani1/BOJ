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
int arr[51][51];
int command[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int X, int Y, int D)
{
    if (arr[X][Y] == 0)
    {
        arr[X][Y] = 9; // 청소 완료
        ans++;
    }
    int nextX, nextY;
    for (int i = 0; i < 4; i++)
    {
        // 북쪽 -> 서쪽
        if (D == 0)
        {
            D = 3;
            nextX = X + command[3][0];
            nextY = Y + command[3][1];
        }
        // 동쪽 -> 북쪽
        else if (D == 1)
        {
            D = 0;
            nextX = X + command[0][0];
            nextY = Y + command[0][1];
        }
        // 남쪽 -> 동쪽
        else if (D == 2)
        {
            D = 1;
            nextX = X + command[1][0];
            nextY = Y + command[1][1];
        }
        // 서쪽 -> 남쪽
        else
        {
            D = 2;
            nextX = X + command[2][0];
            nextY = Y + command[2][1];
        }
        if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M)
        {
            if (arr[nextX][nextY] == 0)
                dfs(nextX, nextY, D);
        }
    }
    // 북쪽
    if (D == 0)
    {
        nextX = X + command[2][0];
        nextY = Y + command[2][1];
    }
    // 동쪽
    else if (D == 1)
    {
        nextX = X + command[3][0];
        nextY = Y + command[3][1];
    }
    // 남쪽
    else if (D == 2)
    {
        nextX = X + command[0][0];
        nextY = Y + command[0][1];
    }
    // 서쪽
    else
    {
        nextX = X + command[1][0];
        nextY = Y + command[1][1];
    }
    if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M)
    {
        if (arr[nextX][nextY] != 1)
            dfs(nextX, nextY, D);
        else
        {
            cout << ans << "\n";
            exit(0);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int X, Y, D;
    cin >> N >> M >> X >> Y >> D;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
    dfs(X, Y, D);
    cout << ans << "\n";
    return 0;
}
