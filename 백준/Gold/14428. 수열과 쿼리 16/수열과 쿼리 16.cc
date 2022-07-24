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
typedef pair<int, int> pii;

int N, M, K, H = 1;
int A, B, C;
vector<pair<int, int>> tree;
vector<int> num;

void update(int idx, int value)
{
    // 단말 노드를 저장한 num배열의 인덱스값이 넘어오기 때문에 포화이진트리에서의 단말노드 번호로 바꿔준는 과정
    // num배열의 0번째 원소 -> 첫번째 단말노드 -> 8번째 노드이므로 높이 H 값을 더해주면 된다
    int numIdx = idx + 1;
    idx += H;
    tree[idx].first = value;
    tree[idx].second = numIdx;
    // 루트노드까지 값들을 갱신시켜준다.
    while (idx > 1)
    {
        idx /= 2;
        tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
    }
}

pii query(int L, int R, int node, int nodeL, int nodeR) // 찾는 범위 왼쪽 값, 찾는 범위 오른쪽 값, 해당 노드 번호, 해당 노드의 왼쪽 범위, 해당 노드의 오른쪽 범위
{
    if (L <= nodeL && nodeR <= R) // 원하는 값을 노드에서 포함하고 있는 경우
        return tree[node];        // 최소, 최대 값을 쌍으로 반환
    if (nodeR < L || R < nodeL)   // 원하는 범위를 노드에서 포함하고 있지 않은 경우 {max, max} 값으로 반환
        return make_pair(1e9, 1e9);
    int mid = (nodeL + nodeR) / 2;
    // 왼쪽에서의 최소, 최대값 / 오른족에서의 최소, 최대값을 쌍으로 탐색 후 반환
    return min(query(L, R, node * 2, nodeL, mid), query(L, R, node * 2 + 1, mid + 1, nodeR)); // 타입을 맞춰주면 알아서 1. 값, 2.인덱스 순서로 비교해서 반환
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    // 단말 노드의 개수 구하기
    while (N > H)
    {
        H *= 2;
    }
    num.resize(N + 1);
    tree.assign(H * 2, {1e9, 1e9});
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        update(i, num[i]);
    }
    cin >> M;
    pii result;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B >> C;
        if (A == 1)
            update(B - 1, C);
        else if (A == 2)
        {
            result = query(B, C, 1, 1, H);
            cout << result.second << "\n";
        }
    }
    return 0;
}
