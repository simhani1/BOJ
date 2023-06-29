#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 1234567890
typedef long long ll;

int C, P, ans;
int arr[101];

int solve1(void)
{
    int cnt = 0;
    // 1
    cnt += C;
    // 2
    for (int i = 3; i < C; i++)
    {
        if (arr[i - 3] == arr[i - 2] && arr[i - 2] == arr[i - 1] && arr[i - 1] == arr[i])
            cnt++;
    }
    return cnt;
}

int solve2(void)
{
    int cnt = 0;
    // 1
    for (int i = 1; i < C; i++)
    {
        if (arr[i - 1] == arr[i])
            cnt++;
    }
    return cnt;
}

int solve3(void)
{
    int cnt = 0;
    // 1
    for (int i = 2; i < C; i++)
    {
        if (arr[i - 2] == arr[i - 1] && arr[i - 1] + 1 == arr[i])
            cnt++;
    }
    // 2
    for (int i = 1; i < C; i++)
    {
        if (arr[i - 1] - 1 == arr[i])
            cnt++;
    }
    return cnt;
}

int solve4(void)
{
    int cnt = 0;
    // 1
    for (int i = 2; i < C; i++)
    {
        if (arr[i - 2] - 1 == arr[i - 1] && arr[i - 1] == arr[i])
            cnt++;
    }
    // 2
    for (int i = 1; i < C; i++)
    {
        if (arr[i - 1] + 1 == arr[i])
            cnt++;
    }
    return cnt;
}

int solve5(void)
{
    int cnt = 0;
    // 1
    for (int i = 2; i < C; i++)
    {
        if (arr[i - 2] == arr[i - 1] && arr[i - 1] == arr[i])
            cnt++;
    }
    // 2
    for (int i = 1; i < C; i++)
    {
        if (arr[i - 1] - 1 == arr[i])
            cnt++;
    }
    // 3
    for (int i = 2; i < C; i++)
    {
        if (arr[i - 2] - 1 == arr[i - 1] && arr[i - 1] + 1 == arr[i])
            cnt++;
    }
    // 4
    for (int i = 1; i < C; i++)
    {
        if (arr[i - 1] + 1 == arr[i])
            cnt++;
    }
    return cnt;
}

int solve6(void)
{
    int cnt = 0;
    // 1
    for (int i = 2; i < C; i++)
    {
        if (arr[i - 2] == arr[i - 1] && arr[i - 1] == arr[i])
            cnt++;
    }
    // 2
    for (int i = 1; i < C; i++)
    {
        if (arr[i - 1] - 2 == arr[i])
            cnt++;
    }
    // 3
    for (int i = 2; i < C; i++)
    {
        if (arr[i - 2] + 1 == arr[i - 1] && arr[i - 1] == arr[i])
            cnt++;
    }
    // 4
    for (int i = 1; i < C; i++)
    {
        if (arr[i - 1] == arr[i])
            cnt++;
    }
    return cnt;
}

int solve7(void)
{
    int cnt = 0;
    // 1
    for (int i = 2; i < C; i++)
    {
        if (arr[i - 2] == arr[i - 1] && arr[i - 1] == arr[i])
            cnt++;
    }
    // 2
    for (int i = 1; i < C; i++)
    {
        if (arr[i - 1] == arr[i])
            cnt++;
    }
    // 3
    for (int i = 2; i < C; i++)
    {
        if (arr[i - 2] == arr[i - 1] && arr[i - 1] - 1 == arr[i])
            cnt++;
    }
    // 4
    for (int i = 1; i < C; i++)
    {
        if (arr[i - 1] + 2 == arr[i])
            cnt++;
    }
    return cnt;
}

void input(void)
{
    cin >> C >> P;
    for (int i = 0; i < C; i++)
    {
        cin >> arr[i];
    }
    switch (P)
    {
    case 1:
        ans = solve1();
        break;
    case 2:
        ans = solve2();
        break;
    case 3:
        ans = solve3();
        break;
    case 4:
        ans = solve4();
        break;
    case 5:
        ans = solve5();
        break;
    case 6:
        ans = solve6();
        break;
    case 7:
        ans = solve7();
        break;
    }
    cout << ans << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    return 0;
}
