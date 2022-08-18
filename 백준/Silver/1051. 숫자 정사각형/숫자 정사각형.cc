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

int N, M, L = 9999;
int arr[51][51];

int main(void)
{
    cin >> N >> M;
    L = min(N, M); // 정사각형의 최대 길이를 저장
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }
    int ans = 0;
    // 각 점마다 가능한 변의 길이까지 꼭짓점을 탐색
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int maxLength = 0;
            // 1 ~ L-1 까지 주위를 탐색
            for (int k = 0; k < L; k++)
            {
                // 배열의 범위를 벗어나지 않는 경우 탐색
                if ((i + k) < N && (j + k) < M)
                {
                    // 4개의 꼭짓점이 모두 같은 경우 한 변의 최대 길이를 저장
                    if (arr[i][j] == arr[i + k][j] && arr[i][j] == arr[i][j + k] && arr[i][j] == arr[i + k][j + k])
                        maxLength = k + 1;
                }
            }
            ans = max(ans, maxLength);
        }
    }
    cout << ans * ans;
    return 0;
}
