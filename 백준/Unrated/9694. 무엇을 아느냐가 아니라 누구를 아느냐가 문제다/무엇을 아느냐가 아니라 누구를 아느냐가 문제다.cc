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

int T, N, M;
int dist[21], parent[21];
vector<pair<int, int>> edge[21];

void printRoute(int round)
{
    stack<int> ans;
    if (dist[M - 1] == INF)
        cout << "Case #" << round << ": " << -1 << "\n";
    else
    {
        int now = M - 1;
        while (true)
        {
            ans.push(now);
            if (now == 0)
                break;
            now = parent[now];
        }
        cout << "Case #" << round << ": ";
        while (!ans.empty())
        {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << "\n";
    }
}

void solve(int round)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    parent[0] = 0;
    dist[0] = 0;
    while (!pq.empty())
    {
        int now = pq.top().second;
        int nowDist = pq.top().first;
        pq.pop();
        if (dist[now] < nowDist)
            continue;
        for (int i = 0; i < edge[now].size(); i++)
        {
            int next = edge[now][i].first;
            int nextDist = edge[now][i].second;
            if (dist[next] > dist[now] + nextDist)
            {
                dist[next] = dist[now] + nextDist;
                pq.push({dist[next], next});
                parent[next] = now; // 제일 빠르게 현재 노드까지 도달 가능한 부모를 저장
            }
        }
    }
    printRoute(round);
}

void init(void)
{
    for (int i = 0; i <= M; i++)
    {
        dist[i] = INF;
        parent[i] = INF;
        edge[i].clear();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N >> M;
        init();
        for (int i = 0, X, Y, Z; i < N; i++)
        {
            cin >> X >> Y >> Z;
            edge[X].push_back({Y, Z});
            edge[Y].push_back({X, Z});
        }
        solve(t);
    }
    return 0;
}
