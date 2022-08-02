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

int N, M;
int depth[50001], parent[50001];
bool visited[50001];
vector<vector<int>> tree;

// DFS로 각 노드의 높이를 저장
void DFS(int now, int level)
{
    visited[now] = true;
    depth[now] = level;
    for (auto next : tree[now])
    {
        if (!visited[next])
        {
            parent[next] = now;
            DFS(next, level + 1);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    tree.resize(N + 1);
    // 트리 정보 저장
    // 노드의 개수는 N개지만 입력받는 정보는 N-1개
    for (int i = 1, A, B; i < N; i++)
    {
        cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }
    DFS(1, 1);
    cin >> M;
    for (int i = 1, A, B; i <= M; i++)
    {
        cin >> A >> B;
        // 항상 B노드의 깊이가 더 깊도록 통일시키기
        if (depth[A] > depth[B])
            swap(A, B);
        // 두 노드의 높이가 동일해질 때까지 B의 노드에서 위쪽으로 한칸씩 탐색
        while (depth[A] != depth[B])
        {
            B = parent[B];
        }
        // 두 노드의 부모노드가 동일할 때까지 위로 탐색
        while (A != B)
        {
            A = parent[A];
            B = parent[B];
        }
        // 공통 조상 출력
        cout << A << "\n";
    }
    return 0;
}
