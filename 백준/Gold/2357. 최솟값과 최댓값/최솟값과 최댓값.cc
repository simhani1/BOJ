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
int A, B;
vector<int> minTree, maxTree;
vector<int> num;

void update(int idx, int value)
{
    // 단말 노드를 저장한 num배열의 인덱스값이 넘어오기 때문에 포화이진트리에서의 단말노드 번호로 바꿔준는 과정
    // num배열의 0번째 원소 -> 첫번째 단말노드 -> 8번째 노드이므로 높이 H 값을 더해주면 된다
    idx += H;
    minTree[idx] = value;
    maxTree[idx] = value;
    // 루트노드까지 값들을 갱신시켜준다.
    while (idx > 1)
    {
        idx /= 2;
        // 최솟값, 최댓값을 따로 저장
        minTree[idx] = min(minTree[idx * 2], minTree[idx * 2 + 1]);
        maxTree[idx] = max(maxTree[idx * 2], maxTree[idx * 2 + 1]);
    }
}

pair<int, int> query(int L, int R, int node, int nodeL, int nodeR) // 찾는 범위 왼쪽 값, 찾는 범위 오른쪽 값, 해당 노드 번호, 해당 노드의 왼쪽 범위, 해당 노드의 오른쪽 범위
{
    if (L <= nodeL && nodeR <= R)                       // 원하는 값을 노드에서 포함하고 있는 경우
        return make_pair(minTree[node], maxTree[node]); // 최소, 최대 값을 쌍으로 반환
    if (nodeR < L || R < nodeL)                         // 원하는 범위를 노드에서 포함하고 있지 않은 경우
        return make_pair(2147483647, 0);
    int mid = (nodeL + nodeR) / 2;
    // 왼쪽에서의 최소, 최대값 / 오른족에서의 최소, 최대값을 쌍으로 탐색 후 반환
    pair<int, int> left, right;
    left = query(L, R, node * 2, nodeL, mid);
    right = query(L, R, node * 2 + 1, mid + 1, nodeR);
    return make_pair(min(left.first, right.first), max(left.second, right.second));
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
    minTree.assign(H * 2, 2147483647);
    maxTree.assign(H * 2, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
        update(i, num[i]);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        pair<int, int> result = query(A, B, 1, 1, H);
        cout << result.first << " " << result.second << "\n";
    }
    return 0;
}
