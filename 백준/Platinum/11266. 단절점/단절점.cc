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

int V, E, seq, cnt = 0;
int discovered[10001]; // DFS 탐색 순서 저장
bool point[10001];     // 단절점 여부 저장
vector<int> adj[10001];

int dfs(int A, bool isRoot)
{
    discovered[A] = ++seq;
    int ret = discovered[A]; // 인접 노드 중 방문시간이 제일 빠른 노드를 저장
    int child = 0;           // A가 루트노드인 경우 자식 수를 확인
    for (int i = 0; i < adj[A].size(); i++)
    {
        int nextNode = adj[A][i];
        if (!discovered[nextNode])
        {
            child++;
            int low = dfs(nextNode, false);      // low: 정점 A의 자식 노드가 갈 수 있는 노드 중, 제일 빨리 방문한 노드
            if (!isRoot && low >= discovered[A]) // 루트가 아닌 현재 노드의 방문 순서보다 자식 노드의 방문 순서가 더 크거나 같다면 단절점
                point[A] = true;
            ret = min(ret, low);
        }
        else
            ret = min(ret, discovered[nextNode]); // 이미 방문했다면, 현재 정점의 방문 순서와 탐색된 정점의 방문 순서 중 작은값을 찾는다.
    }
    if (isRoot && child >= 2)
        point[A] = true;
    return ret; // A 자식노드가 A를 거치지 않고 도달할 수 있는 정점 중, 제일 먼저 DFS함수가 방문한 정점
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
    for (int i = 1; i <= V; i++)
    {
        if (!discovered[i])
            dfs(i, true);
    }
    for (int i = 1; i <= V; i++)
    {
        if (point[i])
            cnt++;
    }
    cout << cnt << endl;
    for (int i = 1; i <= V; i++)
    {
        if (point[i])
            cout << i << " ";
    }
    return 0;
}
