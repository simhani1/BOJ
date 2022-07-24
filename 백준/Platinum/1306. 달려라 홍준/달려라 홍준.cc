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

int N, M, K, H = 1;
int A, B, C;
vector<int> tree;
vector<int> num;

void update(int idx, int value)
{
    // 단말 노드를 저장한 num배열의 인덱스값이 넘어오기 때문에 포화이진트리에서의 단말노드 번호로 바꿔준는 과정
    // num배열의 0번째 원소 -> 첫번째 단말노드 -> 8번째 노드이므로 높이 H 값을 더해주면 된다
    idx += H;
    tree[idx] = value;
    // 루트노드까지 값들을 갱신시켜준다.
    while (idx > 1)
    {
        idx /= 2;
        tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
    }
}

int query(int L, int R, int node, int nodeL, int nodeR) // 찾는 범위 왼쪽 값, 찾는 범위 오른쪽 값, 해당 노드 번호, 해당 노드의 왼쪽 범위, 해당 노드의 오른쪽 범위
{
    if (L <= nodeL && nodeR <= R) // 원하는 값을 노드에서 포함하고 있는 경우
        return tree[node];        // 최댓값을 저장
    if (nodeR < L || R < nodeL) 
        return 0;
    int mid = (nodeL + nodeR) / 2;
    return max(query(L, R, node * 2, nodeL, mid), query(L, R, node * 2 + 1, mid + 1, nodeR));
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
    num.resize(N + 1);
    tree.assign(H * 2, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        update(i, num[i]);
    }
    // 한칸식 이동하면서 시야 범위에 속하는 최대값을 찾아 출력
    for (int i = M; i <= N - M + 1; i++)
    {
        cout << query(i - (M - 1), i + (M - 1), 1, 1, H) << " ";
    }
    return 0;
}
