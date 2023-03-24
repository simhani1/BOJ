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

int N, M, parent[100001];
ll childCnt[100001];

int Find(int A)
{
    if (A != parent[A])
        parent[A] = Find(parent[A]);
    return parent[A];
}

void Union(int A, int B)
{
    A = Find(A);
    B = Find(B);
    if (A == B)
        return;
    else
    {
        childCnt[Find(A)] += childCnt[B];
        parent[B] = Find(A);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 1, A; i <= N; i++)
    {
        cin >> A;
        childCnt[i] += A;
    }
    for (int i = 0, A, B; i < M; i++)
    {
        cin >> A >> B;
        Union(min(A, B), max(A, B));
        cout << childCnt[parent[min(A, B)]] << "\n";
    }
    return 0;
}
