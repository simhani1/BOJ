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

int N, M, ans = 0;
vector<vector<int>> node(501);
int dist[501];
bool visited[501];

void solve(void)
{
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < node[now].size(); i++)
        {
            int next = node[now][i];
            if (!visited[next])
            {
                visited[next] = true;
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0, A, B; i < M; i++)
    {
        cin >> A >> B;
        node[A].push_back(B);
        node[B].push_back(A);
    }
    solve();
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == 1 || dist[i] == 2)
            ans++;
    }
    cout << ans << endl;
    return 0;
}