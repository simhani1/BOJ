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

int N, M;
int arr[101][101];
bool visited[101][101];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void input(void)
{
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }
}

void solve(void)
{
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, 0}});
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int nowX = pq.top().second.first;
        int nowY = pq.top().second.second;
        pq.pop();
        if (visited[nowX][nowY])
            continue;
        visited[nowX][nowY] = true;
        if (nowX == N - 1 && nowY == M - 1)
        {
            cout << cost << "\n";
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
                continue;
            if (arr[nextX][nextY] == 1)
                pq.push({-(cost + 1), {nextX, nextY}});
            else
                pq.push({-cost, {nextX, nextY}});
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
