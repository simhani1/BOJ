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
#define MAX 987654321
#define INIT 100000000
typedef long long ll;

int N, K;
int dx[] = {-1, 1};
set<int> visited;
queue<int> q;
ll ans = 0;

void bfs(void)
{
    ll dist = 1;
    while (!q.empty())
    {
        int candidate = q.size();
        // 현재 탐색을 진행할 후보 수 만큼 bfs탐색을 통해 좌우에 집을 지을 수 있는지 판단해야 한다.
        // 한번 후보들에 대해서 탐색이 종료되면 그 다음부터 짓는 집들의 불행도는 이전보다 1 증가하기 때문이다.
        while (candidate--)
        {
            int now = q.front();
            q.pop();
            visited.insert(now);
            for (int i = 0; i < 2; i++)
            {
                if (K == 0)
                    return;
                int next = now + dx[i];
                if (visited.count(next) == 0)
                {
                    visited.insert(next);
                    q.push(next);
                    ans += dist;
                    K--;
                }
            }
        }
        dist++;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        q.push(X);
        visited.insert(X);
    }
    bfs();
    cout << ans << "\n";
    return 0;
}
