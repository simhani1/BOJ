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
typedef long long ll;

int N, M, K, H = 1;
ll A, B, C;
vector<ll> tree, num;

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

ll query(int L, int R, int node, int nodeL, int nodeR) // 찾는 범위 왼쪽 값, 찾는 범위 오른쪽 값, 해당 노드 번호, 해당 노드의 왼쪽 범위, 해당 노드의 오른쪽 범위
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
    cin >> N >> M;
    // 단말 노드의 개수 구하기
    while (N > H)
    {
        H *= 2;
    }
    tree.resize(H * 2 + 1);
    num.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        if (A == 1)
            update(B - 1, C);
        else
        {
            if (B < C)
                cout << query(B, C, 1, 1, H) << "\n";
            else
                cout << query(C, B, 1, 1, H) << "\n";
        }
    }
    return 0;
}
