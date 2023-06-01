#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 123456789
typedef long long ll;

int T, N, M;
int flow[201][201], capacity[201][201], ans = 0;
vector<int> v[201];

void solve(void)
{
    while (true)
    {
        int parent[201] = {
            0,
        };
        queue<int> q;
        q.push(1);
        while (!q.empty() && !parent[N])
        {
            int now = q.front();
            q.pop();
            if (now == N)
                break;
            for (int next : v[now])
            {
                if (capacity[now][next] - flow[now][next] && !parent[next])
                {
                    q.push(next);
                    parent[next] = now;
                }
            }
        }
        if (!parent[N])
            break;
        int M = INF;
        for (int i = N; i != 1; i = parent[i])
        {
            M = min(M, capacity[parent[i]][i] - flow[parent[i]][i]);
        }
        for (int i = N; i != 1; i = parent[i])
        {
            flow[parent[i]][i] += M;
            flow[i][parent[i]] -= M;
        }
        ans++;
    }
    cout << ans << endl;
}

void init(void)
{
    ans = 0;
    for (int i = 0; i < 201; i++)
    {
        v[i].clear();
        for (int j = 0; j < 201; j++)
        {
            capacity[i][j] = 0;
            flow[i][j] = 0;
        }
    }
}

void input(void)
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        for (int i = 0, A, B; i < M; i++)
        {
            cin >> A >> B;
            int from = min(A, B), to = max(A, B);
            v[from].push_back(to);
            v[to].push_back(from);
            if (from == 1 || to == N)
                capacity[from][to] = 1;
            else
                capacity[from][to] = INF;
        }
        solve();
        init();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    return 0;
}
