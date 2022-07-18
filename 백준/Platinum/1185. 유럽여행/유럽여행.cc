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

int N, P, C;
int S, E, L;
priority_queue<pair<int, pair<int, int>>> pq; // 비용, 나라1, 나라2
int parent[10001];
int cost[10001];
int result = 0;
int minCost = 9999;

// 부모 노드 찾기
int Find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
        parent[y] = x;
}

void Kruskal(void)
{
    while (!pq.empty())
    {
        int u = Find(pq.top().second.first);
        int v = Find(pq.top().second.second);
        int fee = -pq.top().first;
        pq.pop();
        // 두 정점의 부모노드가 동일하다면 사이클이 존재하는 것이므로 padd
        if (u == v)
            continue;
        else
        {
            Union(u, v);
            result += fee;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> P;
    for (int i = 1; i <= N; i++)
    {
        cin >> C;
        cost[i] = C;
        parent[i] = i;
        minCost = min(minCost, C);
    }
    for (int i = 1; i <= P; i++)
    {
        cin >> S >> E >> L;
        int c = cost[S] + cost[E] + 2 * L;
        pq.push({-c, {S, E}});
    }
    Kruskal();
    cout << result + minCost;
    return 0;
}
