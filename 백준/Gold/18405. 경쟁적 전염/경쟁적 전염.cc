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

struct virus
{
    int k;
    int x;
    int y;
};
vector<virus> virusInfo;
int N, K;
int S, X, Y;
int arr[201][201];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool compare(virus A, virus B)
{
    return A.k < B.k;
}

void DFS(void)
{
    int start = 0;
    int end = virusInfo.size();
    while (S--)
    {
        for (int i = start; i < end; i++)
        {
            virus nowVirus = virusInfo[i];
            for (int j = 0; j < 4; j++)
            {
                int nx = nowVirus.x + dx[j];
                int ny = nowVirus.y + dy[j];
                if (1 <= nx && nx <= N && 1 <= ny && ny <= N)
                {
                    // 0일 경우에만 바이러스 확산
                    if (!arr[nx][ny])
                    {
                        arr[nx][ny] = nowVirus.k;
                        virusInfo.push_back({nowVirus.k, nx, ny});
                    }
                }
            }
        }
        // vector를 한 바퀴 돌고, 그 후 탐색해야하는 바이러스 좌표의 시작 인덱스와와 마지막 인덱스를 갱신
        start = end + 1;
        end = virusInfo.size();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
            {
                virusInfo.push_back({arr[i][j], i, j});
            }
        }
    }
    cin >> S >> X >> Y;
    sort(virusInfo.begin(), virusInfo.end(), compare);
    DFS();
    cout << arr[X][Y];
    return 0;
}