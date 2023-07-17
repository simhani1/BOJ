#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 2000000000
typedef long long ll;

int N, M;
int parent[1001];
bool visited[1001];
vector<int> v[1001];

int Find(int A)
{
    if (A == parent[A])
        return A;
    return parent[A] = Find(parent[A]);
}

void Union(int A, int B)
{
    A = Find(A);
    B = Find(B);
    if (A != B)
        parent[max(A, B)] = min(A, B);
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
    for (int i = 0, P, Q; i < M; i++)
    {
        char type;
        cin >> type >> P >> Q;
        if (type == 'F')
            Union(P, Q);
        else
        {
            for (int j = 0; j < v[P].size(); j++)
            {
                Union(Q, v[P][j]);
            }
            for (int j = 0; j < v[Q].size(); j++)
            {
                Union(P, v[Q][j]);
            }
            v[P].push_back(Q);
            v[Q].push_back(P);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        int target = Find(i);
        if (!visited[target])
        {
            visited[target] = true;
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
