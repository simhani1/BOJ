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
#include <set>
using namespace std;
#define INF 987654321
#define INIT 100000000
typedef long long ll;

int N, M, K, H = 1;
ll A, B, C;
vector<ll> v, tree;

void update(int idx, ll value)
{
    idx += H;
    tree[idx] = value;
    while (idx > 1)
    {
        idx /= 2;
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}

ll query(int L, int R, int node, int nodeL, int nodeR)
{
    if (L <= nodeL && nodeR <= R)
        return tree[node];
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
    cin >> N >> M >> K;
    while (N > H)
        H *= 2; // 단말노드: h개 -> 전체 노드의 개수: 2*h-1
    v.resize(N + 1);
    tree.resize(2 * H + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        update(i, v[i]);
    }
    for (int i = 0; i < M + K; i++)
    {
        cin >> A >> B >> C;
        if (A == 1)
            update(B - 1, C);
        else
            cout << query(B, C, 1, 1, H) << "\n";
    }
    return 0;
}
