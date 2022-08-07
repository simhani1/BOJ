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

int N, M, maxLevel = 1;
int depth[100001], dist[100001];
int dp[100001][17]; // N=100000 일때 maxLevel은 16
bool visited[100001];
vector<pair<int, int>> tree[100001];

void dfs(int now, int parent)
{
    visited[now] = true;
    // 현재 depth는 부모의 depth+1
    depth[now] = depth[parent] + 1;
    // base case
    dp[now][0] = parent;
    // 현재 노드의 2^i번째 부모노드 정보 저장
    for (int i = 1; i <= maxLevel; i++)
    {
        dp[now][i] = dp[dp[now][i - 1]][i - 1];
    }
    for (auto next : tree[now])
    {
        if (!visited[next.first])
        {
            // 루트노드로부터 현재 노드까지의 거리를 모두 계산
            dist[next.first] = dist[now] + next.second;
            dfs(next.first, now);
        }
    }
}

int LCA(int A, int B)
{
    // 항상 B노드의 깊이가 더 깊도록 통일시키기
    if (depth[A] > depth[B])
        swap(A, B);
    // A, B의 깊이를 동일하게 설정
    for (int i = maxLevel; i >= 0; i--)
    {
        // 처음으로 A의 깊이보다 낮아지는 순간까지 B의 제일 상위 부모부터 탐색하면서 내려온다
        // 무조건 두 노드의 깊이가 동일해진다
        // 깊이의 차가 홀수더라도 마지막에 1칸만 이동하면 해결이 된다
        if (depth[A] <= depth[dp[B][i]])
            B = dp[B][i];
    }
    // A, B가 동일하다면 최소 공통 조상을 찾은 것이므로 return
    if (A == B)
        return A;
    // 상위 조상부터 탐색하면서 처음으로 조상노드가 달라지는 최초지점을 찾는다
    for (int i = maxLevel; i >= 0; i--)
    {
        if (dp[A][i] != dp[B][i])
        {
            A = dp[A][i];
            B = dp[B][i];
        }
    }
    return dp[A][0]; // 최초로 부모노드가 달라진 노드의 부모노드가 LCA
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    maxLevel = floor(log2(N));
    // 트리 정보 저장
    // 노드의 개수는 N개지만 입력받는 정보는 N-1개
    // 간선의 개수는 (노드의 개수 - 1)
    for (int i = 1, A, B, C; i < N; i++)
    {
        cin >> A >> B >> C;
        tree[A].push_back({B, C});
        tree[B].push_back({A, C});
    }
    // DFS & memoization
    dfs(1, 0);
    cin >> M;
    for (int i = 1, A, B; i <= M; i++)
    {
        cin >> A >> B;
        cout << dist[A] + dist[B] - 2 * dist[LCA(A, B)] << "\n";
    }
    return 0;
}
