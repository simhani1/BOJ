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
int parent[1001];
int result = 0;
int cnt = 1;

int Find(int A)
{
    if (A == parent[A])
        return A;
    else
        return parent[A] = Find(parent[A]);
}

void Union(int A, int B)
{
    A = parent[A];
    B = parent[B];
    if (A > B)
        parent[A] = B;
    else if (A < B)
        parent[B] = A;
}

bool Kruskal(void)
{
    priority_queue<pair<int, pair<int, int> > > pq;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        pq.push(make_pair(C, make_pair(A, B)));
    }
    while (!pq.empty())
    {
        int nowNode = Find(pq.top().second.first);
        int nextNode = Find(pq.top().second.second);
        int cost = pq.top().first;
        pq.pop();
        if (nowNode != nextNode)
        {
            Union(nowNode, nextNode);
            result += cost;
            cnt++;
        }
    }
    if (cnt == N)
        return true;
    else
        return false;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    //모든 노드가 연결되는 경우
    if (Kruskal())
        cout << result;
    //모든 노드가 연결되지 않는 경우
    else
        cout << -1;
    return 0;
}