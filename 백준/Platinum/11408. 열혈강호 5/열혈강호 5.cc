#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;
#define INF 123456789
#define MOD 1000000
typedef long long ll;

vector<int> edge[850];
int c[850][850], f[850][850], pay[850][850];
int N, M, cnt = 0, ans = 0;
int src = 0, dest = 849, work = 400;

void solve(void)
{
    while (true)
    {
        int prev[850], d[850]; // 이전 노드(경로 저장 용도), src로부터의 최단거리
        fill(prev, prev + 850, -1);
        fill(d, d + 850, INF);
        d[src] = 0;
        queue<int> q;
        bool inQ[850];
        q.push(src);
        inQ[src] = true;
        prev[src] = src;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            inQ[now] = false;
            for (int i = 0; i < edge[now].size(); i++)
            {
                int next = edge[now][i];
                int cost = pay[now][next];
                if (c[now][next] - f[now][next] > 0 && d[next] > d[now] + cost)
                {
                    d[next] = d[now] + cost;
                    prev[next] = now;
                    if (!inQ[next])
                    {
                        inQ[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        // SPFA src에서 모든 정점으로 갈 수 있는 최단 거리 구하기 -> d 배열에 저장됨
        if (prev[dest] == -1)
            break; // 더이상의 최단 경로가 없음
        int minFlow = INF;
        for (int i = dest; i != src; i = prev[i])
        {
            minFlow = min(minFlow, c[prev[i]][i] - f[prev[i]][i]); // 경로에서 흐를 수 있는 최소값을 갱신
        }
        for (int i = dest; i != src; i = prev[i])
        {
            ans += (minFlow * pay[prev[i]][i]); // 유량과 월급을 곱한다
            f[prev[i]][i] += minFlow;
            f[i][prev[i]] += -minFlow;
        }
        cnt++;
    }
    cout << cnt << "\n"
         << ans << "\n";
}

void input(void)
{
    // src: 0, dest: 849, 사람: 1 ~ 400, 작업: 401 ~ 800
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        c[src][i] = 1;
        edge[src].push_back(i);
        edge[i].push_back(src);
    }
    // 일과 dest 연결
    for (int i = 1; i <= M; i++)
    {
        c[work + i][dest] = 1;
        edge[dest].push_back(work + i);
        edge[work + i].push_back(dest);
    }
    // 사람과 일 연결
    for (int i = 1; i <= N; i++)
    {
        int len;
        cin >> len;
        for (int j = 0; j < len; j++)
        {
            int to, weight;
            cin >> to >> weight;
            edge[i].push_back(work + to); // 사람이 할 수 있는 일을 연결시킨다
            edge[work + to].push_back(i); // 역방향도 연결시킨다
            pay[i][work + to] = weight;
            pay[work + to][i] = -weight;
            c[i][work + to] = 1; // 최대 작업은 1개이므로 용량을 1로 설정한다
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
