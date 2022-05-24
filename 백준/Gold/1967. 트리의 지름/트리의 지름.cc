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

using namespace std;

int N, P, C, W;
vector<pair<int, int> > tree[10001];
bool visited[10001];
int keyNode;
int maxDist = 0;

// 현재 노드, 처음 시작한 노드로부터 현재 노드까지의 거리
void DFS(int nowNode, int nowDist)
{
    visited[nowNode] = true;
    if (nowDist > maxDist)
    {
        maxDist = nowDist;
        keyNode = nowNode;
    }
    for (int i = 0; i < tree[nowNode].size(); i++)
    {
        int childNode = tree[nowNode][i].first;
        int childDist = tree[nowNode][i].second;
        // 리프 노드에 부모노드에 대한 정보가 있으므로 방문처리가 필요
        if (!visited[childNode])
        {
            visited[childNode] = true;
            DFS(childNode, nowDist + childDist);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        cin >> P >> C >> W;
        tree[P].push_back(make_pair(C, W));
        tree[C].push_back(make_pair(P, W));
    }
    // 루트노드로부터 제일 멀리 떨어진 노드를 찾는다.
    DFS(1, 0);
    memset(visited, false, sizeof(visited));
    // 제일 멀리 떨어진 노드를 시작으로 제일 멀리 덜어진 노드를 찾는다.
    DFS(keyNode, 0);
    cout << maxDist;
    return 0;
}