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

int S;
int arr[1005][5000];
bool visited[1005][5000];

void input(void)
{
    cin >> S;
}

void solve(void)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{1, 0}, 0});
    while (!q.empty())
    {
        int nowLen = q.front().first.first;
        int clipLen = q.front().first.second;
        int time = q.front().second;
        q.pop();
        if (nowLen == S)
        {
            cout << time << "\n";
            return;
        }
        if (nowLen >= 1)
        {
            // 복사
            if (!visited[nowLen][nowLen])
            {
                visited[nowLen][nowLen] = true;
                q.push({{nowLen, nowLen}, time + 1});
            }
            // 삭제
            if (nowLen > 1)
            {
                if (!visited[nowLen - 1][clipLen])
                {
                    visited[nowLen - 1][clipLen] = true;
                    q.push({{nowLen - 1, clipLen}, time + 1});
                }
            }
        }
        if (nowLen + clipLen <= 1000)
        {
            // 붙여넣기
            if (!visited[nowLen + clipLen][clipLen])
            {
                visited[nowLen + clipLen][clipLen] = true;
                q.push({{nowLen + clipLen, clipLen}, time + 1});
            }
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
