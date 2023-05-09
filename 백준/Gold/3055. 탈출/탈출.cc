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

int R, C, startX, startY, goalX, goalY, waterX, waterY;
queue<pair<int, int>> waterPos;
int waterTime[51][51], movingTime[51][51];
char arr[51][51];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
bool visited[51][51];

void waterPropogation(void)
{
    while (!waterPos.empty())
    {
        int nowX = waterPos.front().first;
        int nowY = waterPos.front().second;
        waterPos.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (0 <= nextX && nextX < R && 0 <= nextY && nextY < C)
            {
                if (arr[nextX][nextY] == '.')
                {
                    // 제일 빠르게 물이 차오르는 시간을 갱신
                    if (waterTime[nextX][nextY] > waterTime[nowX][nowY] + 1 && !visited[nextX][nextY])
                    {
                        visited[nextX][nextY] = true;
                        waterTime[nextX][nextY] = waterTime[nowX][nowY] + 1;
                        waterPos.push({nextX, nextY});
                    }
                }
            }
        }
    }
}

int bfs(void)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{startX, startY}, 0});
    visited[startX][startY] = true;
    while (!q.empty())
    {
        int nowX = q.front().first.first;
        int nowY = q.front().first.second;
        int t = q.front().second;
        q.pop();
        if (nowX == goalX && nowY == goalY)
        {
            return t;
        }
        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (0 <= nextX && nextX < R && 0 <= nextY && nextY < C)
            {
                if (!visited[nextX][nextY] && arr[nextX][nextY] != 'X' && arr[nextX][nextY] != '*')
                {
                    if (waterTime[nextX][nextY] > t + 1)
                    {
                        visited[nextX][nextY] = true;
                        q.push({{nextX, nextY}, t + 1});
                    }
                }
            }
        }
    }
    return -1;
}

void initVisited(void)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            visited[i][j] = false;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> arr[i][j];
            waterTime[i][j] = INF;
            movingTime[i][j] = INF;
            char c = arr[i][j];
            if (c == 'D')
            {
                goalX = i;
                goalY = j;
            }
            else if (c == '*')
            {
                waterTime[i][j] = 0;
                waterPos.push({i, j});
            }
            else if (c == 'S')
            {
                startX = i;
                startY = j;
            }
        }
    }
    waterPropogation();
    initVisited();
    int ans = bfs();
    ans == -1 ? cout << "KAKTUS\n" : cout << ans << "\n";
    return 0;
}
