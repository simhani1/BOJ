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

int N, M, K;
int startX, startY; // 시루의 시작위치
int arr[2002][2002];
int visited[2002][2002]; // 각 지점마다 시루가 잃은 체력을 저장하는 배열
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> manequin;
// 기둥: 1  의자: 2  마네퀸: 3  시작점: 4

void fillManequin(void)
{
    // 마네퀸의 도달 가능 지점 미리 계산
    while (K--)
    {
        // 현재 존재하는 마네킹의 이동이 끝날때마다 이동 칸수가 1씩 감소하는 형태
        int cnt = manequin.size();
        while (cnt--)
        {
            int nowX = manequin.front().first;
            int nowY = manequin.front().second;
            manequin.pop();
            for (int i = 0; i < 4; i++)
            {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];
                // 범위에 속하는지 체크
                if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M)
                {
                    // 기둥, 마네킹이 있으면 마네킹이 이동불가
                    if (arr[nextX][nextY] != 1 && arr[nextX][nextY] != 3)
                    {
                        arr[nextX][nextY] = 3;         // 마네킹이 도달 가능한 지역
                        manequin.push({nextX, nextY}); // 새로운 마네킹의 좌표를 push
                    }
                }
            }
        }
    }
}

int bfs(void)
{
    queue<pair<int, int>> siru;
    siru.push({startX, startY});
    while (!siru.empty())
    {
        int nowX = siru.front().first;
        int nowY = siru.front().second;
        siru.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            // 범위에 속하는지 체크
            if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M)
            {
                // 마네퀸과 기둥은 가지 못함
                if (arr[nextX][nextY] != 1 && arr[nextX][nextY] != 3)
                {
                    // 아직 방문하지 않은 지점일 경우 이동
                    if (!visited[nextX][nextY])
                    {
                        visited[nextX][nextY] = visited[nowX][nowY] + 1; // 한칸 씩 이동할때 마다 잃은 체력이 1씩 증가한다.
                        if (arr[nextX][nextY] == 2)
                            return visited[nextX][nextY]; // 의자의 좌표까지 시루가 도달한 경우 잃은 체력 값을 반환
                        siru.push({nextX, nextY});
                    }
                }
            }
        }
    }
    return -1; // 의자에 도달하지 못하는 경우
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 3)
                manequin.push({i, j}); // 마네킹의 좌표를 저장
            else if (arr[i][j] == 4)   // 시루의 좌표 저장
            {
                startX = i;
                startY = j;
            }
        }
    }
    fillManequin();
    cout << bfs();
    return 0;
}
