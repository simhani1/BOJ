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

int N, Q, H = 1;
vector<ll> sum;

void update(int idx, int value)
{
    idx += (H - 1);
    sum[idx] += (ll)value;
    while (idx > 1)
    {
        idx /= 2;
        sum[idx] = sum[idx * 2] + sum[idx * 2 + 1];
    }
}

ll query(int L, int R, int node, int nodeL, int nodeR)
{
    if (L <= nodeL && nodeR <= R)
        return sum[node];
    if (nodeR < L || R < nodeL)
        return 0;
    int mid = (nodeL + nodeR) / 2;
    return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1, nodeR);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    while (N > H)
    {
        H *= 2;
    }
    sum.resize(H * 2 + 1);
    for (int i = 0, type, p, q; i < Q; i++)
    {
        cin >> type >> p >> q;
        if (type == 1)
            update(p, q);
        else
            cout << query(p, q, 1, 1, H) << "\n";
    }
    return 0;
}
