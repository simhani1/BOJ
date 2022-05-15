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

int N, M;
int A, B, C;
int result = 0;
int maxCost = 0;
int parent[100001];

int Find(int A)
{
    if (A == parent[A])
        return A;
    else
        return parent[A] = Find(parent[A]);
}

void Union(int A, int B)
{
    A = Find(A);
    B = Find(B);
    if (A > B)
        parent[A] = B;
    else if (A < B)
        parent[B] = A;
}

void Kruskal(void)
{
    //가중치, 노드1, 노드2
    priority_queue<pair<int, pair<int, int> > > pq;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        pq.push({-C, {A, B}});
    }
    while (!pq.empty())
    {
        int nowNode = Find(pq.top().second.first);
        int nextNode = Find(pq.top().second.second);
        int cost = -pq.top().first;
        pq.pop();
        if (nowNode != nextNode)
        {
            Union(nowNode, nextNode);
            result += cost;
            maxCost = max(maxCost, cost); //최소 신장 트리에서 가중치의 최대값을 찾기
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    Kruskal();
    cout << (result - maxCost);
    return 0;
}