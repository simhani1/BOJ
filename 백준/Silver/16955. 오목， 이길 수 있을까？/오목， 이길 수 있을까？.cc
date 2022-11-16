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

char arr[10][10];
vector<pair<int, int>> v;
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
bool flag;

bool solve(int nowX, int nowY)
{
    for (int i = 0; i < 8; i++)
    {
        int nextX = nowX, nextY = nowY, cntX = 1, cntDot = 0;
        for (int j = 0; j < 4; j++)
        {
            nextX += dx[i];
            nextY += dy[i];
            if (0 <= nextX && nextX < 10 && 0 <= nextY && nextY < 10)
            {
                if (arr[nextX][nextY] == 'X')
                    cntX++;
                else if (arr[nextX][nextY] == '.')
                    cntDot++;
            }
        }
        if (cntX == 4 && cntDot == 1)
            return true;
    }
    return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == 'X')
            {
                bool flag = solve(i, j);
                if (flag)
                {
                    cout << 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
