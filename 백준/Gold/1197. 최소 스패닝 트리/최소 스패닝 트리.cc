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

int V, E;
int A, B, C;
int parent[10001];

int Find(int A)
{
    if (parent[A] == A)
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

int Kruskal(void)
{
    long long result = 0;
    priority_queue<pair<int, pair<int, int> > > pq;
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i <= E; i++)
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
        }
    }
    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;
    cout << Kruskal();
    return 0;
}