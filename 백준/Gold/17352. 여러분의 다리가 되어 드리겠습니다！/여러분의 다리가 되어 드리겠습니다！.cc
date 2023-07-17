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

int N;
int parent[300001];

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
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0, A, B; i < N - 2; i++)
    {
        cin >> A >> B;
        Union(A, B);
    }
    pair<int, int> ans = {parent[1], parent[1]};
    for (int i = 2; i <= N; i++)
    {
        int target = Find(i);
        if (ans.first != target)
        {
            ans.second = target;
            break;
        }
    }
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}
