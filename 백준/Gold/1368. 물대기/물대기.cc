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

int N, W;
int arr[301][301];
int parent[301];
priority_queue<pair<int, pair<int, int>>> pq;
int result = 0;

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
        int cost = -pq.top().first;
        pq.pop();
        // 두 정점의 부모노드가 동일하다면 사이클이 존재하는 것이므로 padd
        if (u == v)
            continue;
        else
        {
            Union(u, v);
            result += cost;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> W;
        pq.push({-W, {0, i}}); // 우물을 0으로 두고 간선 연결
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j]; // 논을 연결하는 비용
            if (i < j)
            {
                pq.push({-arr[i][j], {i, j}});
            }
        }
    }
    Kruskal();
    cout << result;
    return 0;
}
