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

int N, M;
int flow[301][301], capacity[301][301], ans = 0;
vector<int> v[301];

void input(void)
{
    cin >> N >> M;
    for (int i = 0, A, B, C; i < M; i++)
    {
        cin >> A >> B >> C;
        v[A].push_back(B);
        v[B].push_back(A);
        capacity[A][B] += C;
        capacity[B][A] += C;
    }
}

void solve(void)
{
    while (true)
    {
        int parent[301] = {
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
        ans += M;
    }
    cout << ans << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
