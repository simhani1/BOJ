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
#define MAX 9223372036854775807
typedef long long ll;

int N, M, cnt = 0;
vector<int> edge[50001];
bool visited[50001];
int color[50001];

void dfs(int now)
{
    visited[now] = true;
    if (color[now] == 0)
        color[now] = 1;
    for (int i = 0; i < edge[now].size(); i++)
    {
        int next = edge[now][i];
        if (!visited[next])
        {
            if (color[now] == 1)
                color[next] = 2;
            else
                color[next] = 1;
            dfs(next);
        }
    }
}

bool check(void)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < edge[i].size(); j++)
        {
            // 이웃한 정점들과 색깔이 모두 다른지 체크
            if (color[i] == color[edge[i][j]])
                return false;
        }
    }
    return true;
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
        edge[A].push_back(B);
        edge[B].push_back(A);
    }
    dfs(1);
    // 이분 그래프에 대해서 색깔이 서로 다른 두 정점에 또끼와 호랑이가 위치해야 간선의 수가 홀수이므로 만날 수 없음
    if (check())
    {
        for (int i = 1; i <= N; i++)
        {
            if (color[i] == 1)
                cnt++;
        }
    }
    cout << cnt * (N - cnt) * 2 << "\n";
    return 0;
}
