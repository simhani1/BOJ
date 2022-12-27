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
#define MAX 1000000007
typedef long long ll;

int K, V, E;
vector<int> edge[20001];
bool visited[20001];
int color[200001];

bool bfs(int now)
{
    queue<int> q;
    q.push(now);
    color[now] = 1;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        visited[now] = true;
        for (int i = 0; i < edge[now].size(); i++)
        {
            int next = edge[now][i];
            if (!visited[next])
            {
                q.push(next);
                if (color[now] == color[next])
                    return false;
                if (color[now] == 1)
                    color[next] = 2;
                else
                    color[next] = 1;
            }
        }
    }
    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> K;
    while (K--)
    {
        cin >> V >> E;
        for (int i = 0, A, B; i < E; i++)
        {
            cin >> A >> B;
            edge[A].push_back(B);
            edge[B].push_back(A);
        }
        // 주어지는 그래프가 서로 분리된 그래프일 수도 있으므로 모든 정점으로부터 bfs를 탐색
        bool flag = true;
        for (int i = 1; i <= V; i++)
        {
            if (!visited[i])
            {
                if (!bfs(i))
                {
                    flag = false;
                    break;
                }
            }
        }
        flag ? cout << "YES\n" : cout << "NO\n";
        for (int i = 0; i < 20001; i++)
        {
            edge[i].clear();
            visited[i] = false;
            color[i] = 0;
        }
    }
    return 0;
}
