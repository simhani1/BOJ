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

int N, K;
int dist[100001];  // 각 위치까지 걸리는 최소 시간을 저장
bool visited[100001];
int dx[] = {-1, 1, 2};

void dijkstra(void)
{
    priority_queue<pair<int, int>> pq; // 비용 위치
    pq.push({0, N});
    dist[N] = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int now = pq.top().second;
        visited[now] = true;
        pq.pop();
        if (cost > dist[now])
            continue;
        for (int i = 0, next, nextCost; i < 3; i++)
        {
            if (i == 2)
            {
                next = now * dx[i];
                nextCost = cost;
            }
            else
            {
                next = now + dx[i];
                nextCost = cost + 1;
            }
            if (0 <= next && next <= 100000)
            {
                // 아직 방문하지 않은 경우 || 더 짧은 경로가 존재하는 경우
                if (!visited[next] || dist[next] > nextCost)
                {
                    dist[next] = nextCost;
                    pq.push({-nextCost, next});
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
    cin >> N >> K;
    dijkstra();
    cout << dist[K];
    return 0;
}