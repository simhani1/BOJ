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

pair<int, int> start;
pair<int, int> goal;
bool visited[10][9];
int dx[8] = {3, 3, 2, -2, -3, -3, -2, 2};
int dy[8] = {2, -2, -3, -3, -2, 2, 3, 3};

bool check(int x, int y, int type)
{
    int kingX = goal.first;
    int kingY = goal.second;
    if (type == 0)
        if ((kingX == x + 1 && kingY == y) || (kingX == x + 2 && kingY == y + 1))
            return false;
    if (type == 1)
        if ((kingX == x + 1 && kingY == y) || (kingX == x + 2 && kingY == y - 1))
            return false;
    if (type == 2)
        if ((kingX == x && kingY == y - 1) || (kingX == x + 1 && kingY == y - 2))
            return false;
    if (type == 3)
        if ((kingX == x && kingY == y - 1) || (kingX == x - 1 && kingY == y - 2))
            return false;
    if (type == 4)
        if ((kingX == x - 1 && kingY == y) || (kingX == x - 2 && kingY == y - 1))
            return false;
    if (type == 5)
        if ((kingX == x - 1 && kingY == y) || (kingX == x - 2 && kingY == y + 1))
            return false;
    if (type == 6)
        if ((kingX == x && kingY == y + 1) || (kingX == x - 1 && kingY == y + 2))
            return false;
    if (type == 7)
        if ((kingX == x && kingY == y + 1) || (kingX == x + 1 && kingY == y + 2))
            return false;
    return true;
}

int bfs(void)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{start.first, start.second}, 0});
    visited[start.first][start.second] = true;
    while (!q.empty())
    {
        int nowX = q.front().first.first;
        int nowY = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if (nowX == goal.first && nowY == goal.second)
            return cnt;
        for (int i = 0; i < 8; i++)
        {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (0 <= nextX && nextX <= 9 && 0 <= nextY && nextY <= 8)
            {
                if (!visited[nextX][nextY])
                {
                    // 현재 위치를 기준으로 목적지까지 중간에 장애물이 있는지 검사
                    if (check(nowX, nowY, i))
                    {
                        visited[nextX][nextY] = true;
                        q.push({{nextX, nextY}, cnt + 1});
                    }
                }
            }
        }
    }
    return -1;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> start.first >> start.second >> goal.first >> goal.second;
    cout << bfs() << endl;
    return 0;
}
