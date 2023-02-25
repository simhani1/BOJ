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
#define INF 2147483648
typedef long long ll;

int N, M;
vector<int> edge[10001];
vector<pair<int, int>> v;
bool visited[10001];

int bfs(int start)
{
    queue<int> q;
    int cnt = 1;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < edge[now].size(); i++)
        {
            int next = edge[now][i];
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }
    return cnt;
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
        edge[B].push_back(A);
    }
    for (int i = 1; i <= N; i++)
    {
        fill(visited, visited + N + 1, false);
        v.push_back({i, bfs(i)});
    }
    int maxCnt = 0;
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        maxCnt = max(maxCnt, i.second);
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == maxCnt)
            cout << v[i].first << " ";
    }
    return 0;
}
