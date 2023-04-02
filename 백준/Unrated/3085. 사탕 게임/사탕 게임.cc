#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
#define INF 123456789
typedef long long ll;

int N, ans = 0;
char arr[51][51];

void check(void)
{
    // 행에 대하여 연속 사탕의 개수 계산
    for (int i = 0; i < N; i++)
    {
        int cnt = 1; // 일단 사탕 한개는 먹을 수 있음
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == arr[i][j + 1])
                cnt++;
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
    }
    // 열에 대하여 연속 사탕의 개수 계산
    for (int j = 0; j < N; j++)
    {
        int cnt = 1;
        for (int i = 0; i < N; i++)
        {
            if (arr[i][j] == arr[i + 1][j])
                cnt++;
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
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
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    // 시간 복잡도 -> O(N^2 * N^2) = O(N^4)
    // 각 열에 대하여 사탕을 바꾸고 그 순간, 열, 행에 대하여 먹을 수 있는 최대 사탕의 수를 갱신
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            swap(arr[i][j], arr[i][j + 1]);
            check();
            swap(arr[i][j + 1], arr[i][j]);
        }
    }
    // 각 행에 대하여 사탕을 바꾸고 그 순간, 열, 행에 대하여 먹을 수 있는 최대 사탕의 수를 갱신
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N - 1; i++)
        {
            swap(arr[i][j], arr[i + 1][j]);
            check();
            swap(arr[i + 1][j], arr[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}
