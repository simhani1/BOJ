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

int V, E, seq = 0;
int discovered[100001]; // DFS 탐색 순서 저장
vector<int> adj[100001];
vector<pair<int, int>> edge;

int dfs(int A, int parent)
{
    discovered[A] = ++seq;
    int ret = discovered[A]; // 인접 노드 중 방문시간이 제일 빠른 노드를 저장
    for (int i = 0; i < adj[A].size(); i++)
    {
        int next = adj[A][i];
        if (next == parent)
            continue;
        if (!discovered[next])
        {
            int low = dfs(next, A);
            if (low > discovered[A])
                edge.push_back({min(A, next), max(A, next)});
            ret = min(ret, low);
        }
        else
            ret = min(ret, discovered[next]);
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;
    for (int i = 0, A, B; i < E; i++)
    {
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    dfs(1, 0);
    sort(edge.begin(), edge.end());
    cout << edge.size() << "\n";
    for (int i = 0; i < edge.size(); i++)
    {
        cout << edge[i].first << " " << edge[i].second << "\n";
    }
    return 0;
}
