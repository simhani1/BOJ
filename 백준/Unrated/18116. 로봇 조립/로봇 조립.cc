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

int N, parent[1000001], childCnt[1000001];
char type;

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
        childCnt[Find(A)]+=childCnt[B];
        parent[B] = Find(A);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= 1000000; i++)
    {
        parent[i] = i;
        childCnt[i]++;
    }
    for (int i = 0, A, B; i < N; i++)
    {
        cin >> type;
        if (type == 'I')
        {
            cin >> A >> B;
            Union(min(A, B), max(A, B));
        }
        else
        {
            cin >> A;
            int findParent = Find(A);
            cout << childCnt[findParent] << "\n";
        }
    }
    return 0;
}
