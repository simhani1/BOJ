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

int N, Q;
int parent[200001], recordParent[200001];
vector<pair<int, pair<int, int>>> v;
vector<string> ans;

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
        parent[A] = B;
}

void solve(void)
{
    reverse(v.begin(), v.end());
    for (auto i : v)
    {
        if (i.first == 0)
        {
            Union(i.second.first, i.second.second);
        }
        else
        {
            if (Find(i.second.first) == Find(i.second.second))
                ans.push_back("YES\n");
            else
                ans.push_back("NO\n");
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0, A; i < N - 1; i++)
    {
        cin >> A;
        recordParent[i + 2] = A;
    }
    for (int i = 0, X, A, B; i < N + Q - 1; i++)
    {
        cin >> X;
        if (X == 0)
        {
            cin >> A;
            v.push_back({X, {A, recordParent[A]}});
        }
        else
        {
            cin >> A >> B;
            v.push_back({X, {A, B}});
        }
    }
    solve();
    return 0;
}
