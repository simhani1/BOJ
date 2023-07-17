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
#define INF 2000000000
typedef long long ll;

int N, K, minAns = 0, maxAns = 0;
int parent[1001];
bool visited[1001];
priority_queue<pair<int, pair<int, int>>> pq;
vector<pair<int, int>> v[1001];

int Find(int X)
{
    if (X == parent[X])
        return X;
    return parent[X] = Find(parent[X]);
}

void Union(int X, int Y)
{
    X = Find(X);
    Y = Find(Y);
    if (X != Y)
        parent[max(X, Y)] = min(X, Y);
}

void init(void)
{
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }
}

bool diffrentParent(int X, int Y)
{
    return Find(X) != Find(Y);
}

void dfs(int now, int sum)
{
    visited[now] = true;
    for (int i = 0; i < v[now].size(); i++)
    {
        int next = v[now][i].first;
        int cost = v[now][i].second;
        if (!visited[next])
            dfs(next, sum + cost);
    }
    visited[now] = false;
    maxAns = max(maxAns, sum);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 0, A, B, C; i < K; i++)
    {
        cin >> A >> B >> C;
        pq.push({-C, {A, B}});
    }
    init();
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int from = pq.top().second.first;
        int to = pq.top().second.second;
        pq.pop();
        if (diffrentParent(from, to))
        {
            Union(from, to);
            v[from].push_back({to, cost});
            v[to].push_back({from, cost});
            minAns += cost;
        }
    }
    for (int i = 0; i < N; i++)
    {
        dfs(i, 0);
    }
    cout << minAns << "\n"
         << maxAns << "\n";
    return 0;
}
