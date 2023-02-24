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

int N, M, ans;
vector<pair<int, int>> edge[1001];
bool visited[1001];

int dfs(int from, int to, int sum)
{
    visited[from] = true;
    for (int i = 0; i < edge[from].size(); i++)
    {
        int next = edge[from][i].first;
        int dist = edge[from][i].second;
        if (next == to)
        {
            ans = sum + dist;
            break;
        }
        if (!visited[next])
            dfs(next, to, sum + dist);
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1, A, B, C; i < N; i++)
    {
        cin >> A >> B >> C;
        edge[A].push_back({B, C});
        edge[B].push_back({A, C});
    }
    for (int i = 0, A, B; i < M; i++)
    {
        cin >> A >> B;
        ans = 0;
        fill(visited, visited + 1001, false);
        cout << dfs(A, B, 0) << "\n";
    }
    return 0;
}
