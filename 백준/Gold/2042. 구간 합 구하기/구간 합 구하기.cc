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

int N, M, K;
ll arr[1000001];
vector<ll> tree;

void update(ll idx, ll value)
{
    while (idx < tree.size())
    {
        tree[idx] += value;
        idx += (idx & -idx);
    }
}

ll sum(ll idx)
{
    ll result = 0;
    while (idx > 0)
    {
        result += tree[idx];
        idx -= (idx & -idx);
    }
    return result;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    tree.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        update(i, arr[i]);
    }
    for (int i = 0; i < M + K; i++)
    {
        ll A, B, C;
        cin >> A >> B >> C;
        if (A == 1)
        {
            update(B, C - arr[B]);
            arr[B] = C;
        }
        else
            cout << sum(C) - sum(B - 1) << "\n";
    }
    return 0;
}
