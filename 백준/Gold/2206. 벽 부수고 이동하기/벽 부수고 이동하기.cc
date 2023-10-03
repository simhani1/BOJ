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

int N, M;
int arr[1001][1001], dp[1001][1001];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
bool visited[1001][1001][2];
bool flag = false;

void input(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }
}

void solve(void)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 0});
    dp[0][0] = 1;
    visited[0][0][0] = true;
    visited[0][0][1] = true;
    while (!q.empty())
    {
        int nowX = q.front().first.first;
        int nowY = q.front().first.second;
        int crack = q.front().second;
        q.pop();
        if (nowX == N - 1 && nowY == M - 1)
            break;
        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
                continue;
            // 이동 가능한 경우
            if (arr[nextX][nextY] == 0 && !visited[nextX][nextY][crack])
            {
                visited[nextX][nextY][crack] = true;
                dp[nextX][nextY] = dp[nowX][nowY] + 1;
                q.push({{nextX, nextY}, crack});
            }
            // 벽이고 벽을 부순적이 없다면
            if (arr[nextX][nextY] == 1 && !crack && !visited[nextX][nextY][1])
            {
                visited[nextX][nextY][1] = true;
                dp[nextX][nextY] = dp[nowX][nowY] + 1;
                q.push({{nextX, nextY}, 1});
            }
        }
    }
    (dp[N - 1][M - 1] != 0) ? cout << dp[N - 1][M - 1] << "\n" : cout << -1 << "\n";
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
