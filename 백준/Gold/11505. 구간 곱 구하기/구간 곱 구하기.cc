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
vector<ll> tree;
vector<ll> num;

void update(int idx, ll value)
{
    // 단말 노드를 저장한 num배열의 인덱스값이 넘어오기 때문에 포화이진트리에서의 단말노드 번호로 바꿔준는 과정
    // num배열의 0번째 원소 -> 첫번째 단말노드 -> 8번째 노드이므로 높이 H 값을 더해주면 된다
    idx += H;
    tree[idx] = value;
    // 루트노드까지 값들을 갱신시켜준다.
    // 값들의 곲을 1000000007으로 나눈 나머지 값들을 저장
    while (idx > 1)
    {
        idx /= 2;
        tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % 1000000007;
    }
}

ll query(int L, int R, int node, int nodeL, int nodeR) // 찾는 범위 왼쪽 값, 찾는 범위 오른쪽 값, 해당 노드 번호, 해당 노드의 왼쪽 범위, 해당 노드의 오른쪽 범위
{
    if (L <= nodeL && nodeR <= R) // 원하는 값을 노드에서 포함하고 있는 경우
        return tree[node];
    if (nodeR < L || R < nodeL) // 원하는 범위를 노드에서 포함하고 있지 않은 경우
        return 1;
    int mid = (nodeL + nodeR) / 2;
    return (query(L, R, node * 2, nodeL, mid) * query(L, R, node * 2 + 1, mid + 1, nodeR)) % 1000000007; // 현재 노드에서 원하는 값을 찾지 못했으므로 자식 노드로 탐색을 진행
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    // 단말 노드의 개수 구하기
    while (N > H)
    {
        H *= 2;
    }
    num.resize(N + 1);
    tree.assign(H * 2, 1);
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        update(i, num[i]);
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
