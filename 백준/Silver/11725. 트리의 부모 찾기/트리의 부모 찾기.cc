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

int N;
vector<vector<int>> tree(100001);
int parent[100001];

void BFS(void)
{
    queue<int> q;
    q.push(1);
    parent[1] = 1;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < tree[now].size(); i++)
        {
            int next = tree[now][i];
            if (!parent[next])
            {
                q.push(next);
                parent[next] = now;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1, A, B; i < N; i++)
    {
        cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }
    BFS();
    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << "\n";
    }
    return 0;
}
