#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
#define INF 123456789
typedef long long ll;

int P, W, from, to;
int parent[1001];
priority_queue<pair<int, pair<int, int>>> edge;

int Find(int A)
{
    if (parent[A] == A)
        return A;
    return parent[A] = Find(parent[A]);
}

void Union(int A, int B)
{
    A = Find(A);
    B = Find(B);
    if (A == B)
        return;
    parent[B] = A;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> P >> W;
    cin >> from >> to;
    for (int i = 1; i <= P; i++)
    {
        parent[i] = i;
    }
    for (int i = 0, A, B, C; i < W; i++)
    {
        cin >> A >> B >> C;
        edge.push({C, {A, B}});
    }
    while (!edge.empty())
    {
        int cost = edge.top().first;
        int A = edge.top().second.first;
        int B = edge.top().second.second;
        edge.pop();
        Union(min(A, B), max(A, B));
        if (Find(from) == Find(to))
        {
            cout << cost << "\n";
            break;
        }
    }
    return 0;
}
