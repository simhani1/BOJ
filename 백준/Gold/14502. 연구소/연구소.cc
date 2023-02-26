#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
#define INF 2147483648
typedef long long ll;

int N, M, ans = 0;
int arr[9][9], tmp[9][9], virus[9][9];
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
bool visited[9][9];
queue<pair<int, int>> q;

int bfs(void)
{
    int cnt = 0;
    while (!q.empty())
    {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();
        visited[nowX][nowY] = true;
        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M && !visited[nextX][nextY])
            {
                if (virus[nextX][nextY] == 0)
                {
                    virus[nextX][nextY] = 2;
                    q.push({nextX, nextY});
                }
            }
        }
    }
    // 안전구역 크기 계산
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (virus[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

void init(void)
{
    // 초기화 및 벽을 세운 정보 복사하기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
            virus[i][j] = tmp[i][j];
            // 바이러스의 위치 저장
            if (tmp[i][j] == 2)
                q.push({i, j});
        }
    }
}

void makeWall(int idx)
{
    // 임의의 벽 3개 세우기
    if (idx == 3)
    {
        init();
        ans = max(ans, bfs());
        return;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!tmp[i][j])
            {
                tmp[i][j] = 1;
                makeWall(idx + 1);
                tmp[i][j] = 0;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            tmp[i][j] = arr[i][j];
        }
    }
    makeWall(0);
    cout << ans << "\n";
    return 0;
}
