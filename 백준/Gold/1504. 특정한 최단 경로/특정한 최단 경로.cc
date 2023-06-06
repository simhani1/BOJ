#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 123456789
typedef long long ll;

int N, E, V1, V2;
vector<pair<int, int>> v[801];
int dist[801];

void init(void)
{
    for (int i = 0; i < 801; i++)
    {
        dist[i] = INF;
    }
}

void dijkstra(int start)
{
    init();
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for (int i = 0; i < v[now].size(); i++)
        {
            int next = v[now][i].first;
            int nextCost = v[now][i].second;
            if (dist[now] + nextCost < dist[next])
            {
                dist[next] = dist[now] + nextCost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int solve(void)
{
    dijkstra(1);
    int startToV1 = dist[V1];
    int startToV2 = dist[V2];

    dijkstra(V1);
    int V1ToV2 = dist[V2];
    int V2ToV1 = V1ToV2;
    int V1ToN = dist[N];

    dijkstra(V2);
    int V2ToN = dist[N];

    int ans = INF;
    ans = min(ans, startToV1 + V1ToV2 + V2ToN);
    ans = min(ans, startToV2 + V2ToV1 + V1ToN);
    if (ans >= INF)
        return -1;
    else
        return ans;
}

void input(void)
{
    cin >> N >> E;
    for (int i = 0, A, B, C; i < E; i++)
    {
        cin >> A >> B >> C;
        v[A].push_back({B, C});
        v[B].push_back({A, C});
    }
    cin >> V1 >> V2;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    cout << solve() << "\n";
    return 0;
}
