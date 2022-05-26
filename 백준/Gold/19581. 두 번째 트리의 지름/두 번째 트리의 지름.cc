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

int N, A, B, W;
int keyNode, maxDist;
vector<pair<int, int> > tree[100001]; // 노드, 가중치
bool visited[100001];
vector<int> ans;

void DFS(int nowNode, int nowDist, int deleteNode)
{
    visited[nowNode] = true;
    if (nowDist > maxDist && nowNode != deleteNode)
    {
        maxDist = nowDist;
        keyNode = nowNode;
    }
    for (int i = 0; i < tree[nowNode].size(); i++)
    {
        int nextNode = tree[nowNode][i].first;
        int nextDist = tree[nowNode][i].second;
        if (!visited[nextNode])
            DFS(nextNode, nowDist + nextDist, deleteNode);
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
        cin >> A >> B >> W;
        tree[A].push_back(make_pair(B, W));
        tree[B].push_back(make_pair(A, W));
    }
    // 루트 노드로부터 제일 멀리 떨어진 노드를 찾기
    maxDist = 0;
    DFS(1, 0, 0);
    int startNode = keyNode;
    // startNode를 기준으로 제일 멀리 떨어진 노드 찾기
    memset(visited, false, sizeof(visited));
    maxDist = 0;
    DFS(startNode, 0, 0);
    int endNode = keyNode;
    // startNode 부터 endNode를 제외하고 긴 거리 구하기
    memset(visited, false, sizeof(visited));
    maxDist = 0;
    DFS(startNode, 0, endNode);
    ans.push_back(maxDist);
    // endNode 부터 startNode를 제외하고 긴 거리 구하기
    memset(visited, false, sizeof(visited));
    maxDist = 0;
    DFS(endNode, 0, startNode);
    ans.push_back(maxDist);
    // 두 거리중 더 긴 거리를 출력
    ans[0] >= ans[1] ? cout << ans[0] : cout << ans[1];
    return 0;
}