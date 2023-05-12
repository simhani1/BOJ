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
#define INF 123456789

int T, row = 5, col = 9, pinAns = 0, movingAns;
char arr[5][9];
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

int input(void)
{
    int cnt = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'o')
                cnt++;
        }
    }
    return cnt;
}

bool outbound(int nextX, int nextY, int doubleX, int doubleY)
{
    if (nextX < 0 || nextX >= row || nextY < 0 || nextY >= col)
        return true;
    if (doubleX < 0 || doubleX >= row || doubleY < 0 || doubleY >= col)
        return true;
    return false;
}

bool cannotMove(int nextX, int nextY, int doubleX, int doubleY)
{
    if (arr[nextX][nextY] == 'o' && arr[doubleX][doubleY] == '.')
        return false;
    return true;
}

void changeArr(int nowX, int nowY, int nextX, int nextY, int doubleX, int doubleY)
{
    arr[nowX][nowY] = '.';
    arr[nextX][nextY] = '.';
    arr[doubleX][doubleY] = 'o';
}

void rollbackArr(int nowX, int nowY, int nextX, int nextY, int doubleX, int doubleY)
{
    arr[nowX][nowY] = 'o';
    arr[nextX][nextY] = 'o';
    arr[doubleX][doubleY] = '.';
}

bool isNotPin(int nowX, int nowY)
{
    if (arr[nowX][nowY] == 'o')
        return false;
    return true;
}

void updateAnswer(int movingCnt)
{
    int cnt = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 'o')
                cnt++;
        }
    }
    if (cnt <= pinAns)
    {
        pinAns = cnt;
        movingAns = movingCnt;
    }
}

void dfs(int movingCnt)
{
    bool flag = false;
    for (int nowX = 0; nowX < row; nowX++)
    {
        for (int nowY = 0; nowY < col; nowY++)
        {
            if (isNotPin(nowX, nowY))
                continue;
            for (int i = 0; i < 4; i++)
            {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                int doubleX = nowX + 2 * dx[i];
                int doubleY = nowY + 2 * dy[i];
                if (outbound(nextX, nextY, doubleX, doubleY))
                    continue;
                if (cannotMove(nextX, nextY, doubleX, doubleY))
                    continue;
                flag = true;
                changeArr(nowX, nowY, nextX, nextY, doubleX, doubleY);
                dfs(movingCnt + 1);
                rollbackArr(nowX, nowY, nextX, nextY, doubleX, doubleY);
            }
        }
    }
    if (!flag)
        updateAnswer(movingCnt);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        pinAns = input();
        movingAns = INF;
        dfs(0);
        cout << pinAns << " " << movingAns << "\n";
    }
    return 0;
}
