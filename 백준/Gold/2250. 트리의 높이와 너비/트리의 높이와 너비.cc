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

using namespace std;

int N, D, L, R;
pair<int, int> tree[10001];
vector<int> table[10001];
int ans[10001];
int nodeCnt[10001];
int root, idx = 1, maxDepth = 1;

void inorderTraversal(int nowNode, int depth)
{
    if (nowNode == -1)
        return;
    maxDepth = max(maxDepth, depth);
    inorderTraversal(tree[nowNode].first, depth + 1);
    table[depth].push_back(idx++);
    inorderTraversal(tree[nowNode].second, depth + 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> D >> L >> R;
        nodeCnt[D]++;
        nodeCnt[L]++;
        nodeCnt[R]++;
        tree[D] = make_pair(L, R);
    }
    // 한 번만 입력된 노드가 루트노드
    for (int i = 1; i <= N; i++)
    {
        if (nodeCnt[i] == 1)
        {
            root = i;
            break;
        }
    }
    inorderTraversal(root, 1);
    int diameter = 0;
    int ansDepth = 999999999;
    // 각 레벨마다 너비를 저장
    for (int i = 1; i <= maxDepth; i++)
    {
        ans[i] = table[i][table[i].size() - 1] - table[i][0] + 1;
        diameter = max(diameter, table[i][table[i].size() - 1] - table[i][0] + 1);
    }
    // 최대 너비를 갖는 레벨 중, 제일 낮은 레벨을 찾아서 출력
    for (int i = 1; i <= maxDepth; i++)
    {
        if (ans[i] == diameter)
        {
            ansDepth = min(ansDepth, i);
        }
    }
    cout << ansDepth << " " << diameter;
    return 0;
}