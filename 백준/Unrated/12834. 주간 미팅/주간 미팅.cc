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

int N, V, E, A, B, ans = 0;
int dist[10001];
vector<pair<int, int>> edge[10001];
vector<int> v;

int solve(int start)
{
    int d = 0;
    fill(dist, dist + 10001, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        int nowCost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] < nowCost)
            continue;
        for (int i = 0; i < edge[now].size(); i++)
        {
            int next = edge[now][i].first;
            int nextCost = edge[now][i].second;

            if (dist[next] > dist[now] + nextCost)
            {
                dist[next] = dist[now] + nextCost;
                pq.push({-nextCost, next});
            }
        }
    }
    if (dist[A] != INF)
        d += dist[A];
    else
        d--;
    if (dist[B] != INF)
        d += dist[B];
    else
        d--;
    return d;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> V >> E;
    cin >> A >> B;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        v.push_back(X);
    }
    for (int i = 0, X, Y, Z; i < E; i++)
    {
        cin >> X >> Y >> Z;
        edge[X].push_back({Y, Z});
        edge[Y].push_back({X, Z});
    }
    for (auto i : v)
    {
        ans += solve(i);
    }
    cout << ans << "\n";
    return 0;
}
