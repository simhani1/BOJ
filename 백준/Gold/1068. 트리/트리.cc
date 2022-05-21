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

int N, P, root;
int deleteNode;
int leaf = 0;
vector<int> tree[50];

void DFS(int nowNode)
{
    //현재 노드가 삭제하는 노드면 종료
    if (nowNode == deleteNode)
    {
        return;
    }
    //현재 노드에 자식 노드가 없으면 리프노드
    if (!tree[nowNode].size())
    {
        leaf++;
        return;
    }
    //자식 노드의 개수가 1개이면서 삭제하려는 노드일 경우, 리프노드
    else if (tree[nowNode].size() == 1)
    {
        if (tree[nowNode][0] == deleteNode)
        {
            leaf++;
            return;
        }
    }
    //현재 노드의 자식 노드들에 대해서 DFS실행
    for (int i = 0; i < tree[nowNode].size(); i++)
    {
        DFS(tree[nowNode][i]);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        //부모 노드에 자식 노드들의 번호를 저장
        cin >> P;
        if (P == -1)
            root = i;
        else
            tree[P].push_back(i);
    }
    cin >> deleteNode;
    DFS(root);
    cout << leaf;
    return 0;
}