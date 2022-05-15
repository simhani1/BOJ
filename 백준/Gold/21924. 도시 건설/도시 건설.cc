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
long long result = 0;
long long costSum = 0;
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

bool Kruskal(void)
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
        pq.push(make_pair(-C, make_pair(A, B)));
        costSum += C;
    }
    //최소 신장 트리를 구성하는 노드의 개수를 저장
    int cnt = 1;
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
    //노드가 모두 연결 가능한 경우
    if (Kruskal())
        cout << (costSum - result);
    //모두 연결 불가능한 경우
    else
        cout << -1;
    return 0;
}