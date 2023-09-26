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

int N, T;
int arr[100][100];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
bool visited[100][100][3];
priority_queue<pair<int, pair<int, pair<int, int>>>> pq;

void input(void)
{
    cin >> N >> T;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void solve(void)
{
    pq.push({0, {0, {0, 0}}});
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int visitedCnt = pq.top().second.first;
        int x = pq.top().second.second.first;
        int y = pq.top().second.second.second;
        pq.pop();
        if (visited[x][y][visitedCnt])
            continue;
        visited[x][y][visitedCnt] = true;
        if (x == N - 1 && y == N - 1)
        {
            cout << cost << "\n";
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
                continue;
            // 다음 방문이 3번째라면
            if (visitedCnt == 2)
                pq.push({-(cost + T + arr[nextX][nextY]), {0, {nextX, nextY}}});
            else
                pq.push({-(cost + T), {visitedCnt + 1, {nextX, nextY}}});
        }
    }
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
