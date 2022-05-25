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

int rootIdx;
char preorder[27], inorder[27];

void postorderTraversal(string preorderTraversal, string inorderTraversal)
{
    // 전위 순회 결과에서 제일 첫 번째 노드가 루트 노드이므로 전위 순회 결과가 없으면 할 수 있는 것이 없다.
    if (!preorderTraversal.size())
        return;
    char root = preorderTraversal[0];
    string leftPreorder, leftInorder, rightPreorder, rightInorder;
    for (int i = 0; i < inorderTraversal.size(); i++)
    {
        if (root == inorderTraversal[i])
        {
            rootIdx = i;
            break;
        }
    }
    // 현재 트리에서 루트노드를 기준으로 왼쪽, 오른쪽 서브트리의 노드 정보를 저장
    for (int i = 0; i < rootIdx; i++)
    {
        leftInorder += inorderTraversal[i];
        leftPreorder += preorderTraversal[i + 1];
    }
    for (int i = rootIdx + 1; i < inorderTraversal.size(); i++)
    {
        rightInorder += inorderTraversal[i];
        rightPreorder += preorderTraversal[i];
    }
    // 후위 순회를 출력하므로 L -> R -> D 순서로 탐색하면서 각 서브트리에서의 루트 노드를 출력
    postorderTraversal(leftPreorder, leftInorder);
    postorderTraversal(rightPreorder, rightInorder);
    cout << root;
}

int main(void)
{
    while (scanf("%s %s", preorder, inorder) != EOF)
    {
        string preorderTraversal = preorder;
        string inorderTraversal = inorder;
        postorderTraversal(preorderTraversal, inorderTraversal);
        cout << "\n";
    }
    return 0;
}