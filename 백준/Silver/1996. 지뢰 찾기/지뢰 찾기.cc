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

int N;
int arr[1001][1001];
int ans[1001][1001];
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void bfs(void)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (1 <= x && x <= N && 1 <= y && y <= N)
                {
                    // 지뢰칸이 아닌 경우 지뢰개수 누적
                    if (!arr[x][y])
                        ans[x][y] += arr[i][j];
                }
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            char c;
            cin >> c;
            // 지회칸에 대해서만 지뢰 수를 저장
            if (c != '.')
                arr[i][j] = c - '0';
        }
    }
    bfs();
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            // 지뢰가 있는 칸인 경우
            if (arr[i][j])
                cout << "*";
            // 주변에 10개이상 존재하는 경우
            else if (ans[i][j] >= 10)
                cout << "M";
            // 나머지
            else
                cout << ans[i][j];
        }
        cout << "\n";
    }
    return 0;
}