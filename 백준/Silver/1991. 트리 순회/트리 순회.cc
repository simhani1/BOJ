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

int N;
char D, L, R;
vector<pair<char, char> > tree[27];

void Preorder(char nowNode)
{
    if (nowNode == '.')
        return;
    // D
    cout << nowNode;
    // L
    Preorder(tree[nowNode - 'A'][0].first);
    // R
    Preorder(tree[nowNode - 'A'][0].second);
}

void Inorder(char nowNode)
{
    if (nowNode == '.')
        return;
    // L
    Inorder(tree[nowNode - 'A'][0].first);
    // D
    cout << nowNode;
    // R
    Inorder(tree[nowNode - 'A'][0].second);
}

void Postorder(char nowNode)
{
    if (nowNode == '.')
        return;
    // L
    Postorder(tree[nowNode - 'A'][0].first);
    // R
    Postorder(tree[nowNode - 'A'][0].second);
    // D
    cout << nowNode;
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
        tree[D - 'A'].push_back(make_pair(L, R));
    }
    Preorder('A');
    cout << endl;
    Inorder('A');
    cout << endl;
    Postorder('A');
    cout << endl;
    return 0;
}