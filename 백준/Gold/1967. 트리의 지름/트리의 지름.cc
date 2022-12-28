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

int N, start, maxCost = 0;
vector<pair<int, int>> edge[10001];
bool visited[10001];

void dfs(int now, int cost)
{
    visited[now] = true;
    if (cost > maxCost)
    {
        maxCost = cost;
        start = now;
    }
    for (int i = 0; i < edge[now].size(); i++)
    {
        int next = edge[now][i].first;
        int nextCost = edge[now][i].second;
        if (!visited[next])
            dfs(next, cost + nextCost);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1, A, B, C; i < N; i++)
    {
        cin >> A >> B >> C;
        edge[A].push_back({B, C});
        edge[B].push_back({A, C});
    }
    dfs(1, 0);
    fill(visited, visited + 10001, false);
    maxCost = 0;
    dfs(start, 0);
    cout << maxCost << "\n";
    return 0;
}
