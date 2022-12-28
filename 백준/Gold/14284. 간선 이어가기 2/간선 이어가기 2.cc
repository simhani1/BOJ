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
#define MAX 123456789
typedef long long ll;

int N, M, S, T;
vector<pair<int, int>> edge[5001];
int dist[5001];

int dijkstra(void)
{
    fill(dist, dist + 5001, MAX);
    dist[S] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, S});
    while (!pq.empty())
    {
        int now = pq.top().second;
        pq.pop();
        for (int i = 0; i < edge[now].size(); i++)
        {
            int next = edge[now][i].first;
            int nextCost = edge[now][i].second;
            if (dist[now] + nextCost < dist[next])
            {
                dist[next] = dist[now] + nextCost;
                pq.push({-nextCost, next});
            }
        }
    }
    return dist[T];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0, A, B, C; i < M; i++)
    {
        cin >> A >> B >> C;
        edge[A].push_back({B, C});
        edge[B].push_back({A, C});
    }
    cin >> S >> T;
    cout << dijkstra() << "\n";
    return 0;
}
