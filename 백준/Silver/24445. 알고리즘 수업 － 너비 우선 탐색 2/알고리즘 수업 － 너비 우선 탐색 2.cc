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

int N, M, R;
vector<int> node[100001];
int result[100001];
bool visited[100001];
int cnt = 0;

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        result[now] = ++cnt;
        for (int i = 0; i < node[now].size(); i++)
        {
            int next = node[now][i];
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> R;
    for (int i = 0, A, B; i < M; i++)
    {
        cin >> A >> B;
        node[A].push_back(B);
        node[B].push_back(A);
    }
    for (int i = 1; i <= N; i++)
    {
        sort(node[i].begin(), node[i].end(), greater<int>());
    }
    BFS(R);
    for (int i = 1; i <= N; i++)
    {
        cout << result[i] << "\n";
    }
    return 0;
}
