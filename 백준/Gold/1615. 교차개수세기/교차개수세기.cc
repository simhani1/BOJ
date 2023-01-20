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
#define INF 123456789
#define MAX 2000000000
typedef long long ll;

int N, M, H = 1;
ll ans = 0;
vector<pair<int, int>> edge;
vector<int> tree;

ll query(int L, int R, int node, int nodeL, int nodeR)
{
    if (L <= nodeL && nodeR <= R)
        return tree[node];
    if (nodeR < L || R < nodeL)
        return 0;
    int mid = (nodeL + nodeR) / 2;
    return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1, nodeR);
}

void update(int idx)
{
    idx += (H - 1);
    tree[idx]++;
    while (idx > 1)
    {
        idx /= 2;
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    while (N > H)
        H *= 2;
    tree.resize(2 * H);
    for (int i = 0, A, B; i < M; i++)
    {
        cin >> A >> B;
        edge.push_back({A, B});
    }
    sort(edge.begin(), edge.end());
    for (int i = 0; i < M; i++)
    {
        ans += query(edge[i].second + 1, H, 1, 1, H);
        update(edge[i].second);
    }
    cout << ans << "\n";
    return 0;
}
