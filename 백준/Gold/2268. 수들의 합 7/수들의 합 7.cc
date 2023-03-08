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
#define INF 2147483648
typedef long long ll;

int N, M;
vector<ll> tree;
ll arr[1000001];

ll sum(ll idx)
{
    ll sum = 0;
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(ll idx, ll value)
{
    while (idx < tree.size())
    {
        tree[idx] += value;
        idx += (idx & -idx);
    }
}

void makeTree()
{
    for (int i = 1; i <= N; i++)
        update(i, arr[i]);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    tree.resize(N + 1);
    while (M--)
    {
        ll A, B, C;
        cin >> A >> B >> C;
        if (A == 0)
            cout << sum(max(B, C)) - sum(min(B, C) - 1) << "\n";
        else
        {
            update(B, C - arr[B]);
            arr[B] = C;
        }
    }
    return 0;
}
