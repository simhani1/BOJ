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

int N, rCnt = 0, bCnt = 0, ans = 123456789;
string str;

void solve(void)
{
    for (auto i : str)
    {
        if (i == 'R')
            rCnt++;
        else
            bCnt++;
    }
    // 빨강색 왼쪽으로 넘기기
    int idx = 0, cnt = 0;
    while (str[idx] == 'R')
    {
        cnt++;
        idx++;
    }
    ans = min(ans, rCnt - cnt);
    // 파란색 왼쪽으로 넘기기
    idx = 0, cnt = 0;
    while (str[idx] == 'B')
    {
        cnt++;
        idx++;
    }
    ans = min(ans, bCnt - cnt);
    // 빨강색 오른쪽으로 넘기기
    idx = N - 1, cnt = 0;
    while (str[idx] == 'R')
    {
        cnt++;
        idx--;
    }
    ans = min(ans, rCnt - cnt);
    // 파란색 오른쪽으로 넘기기
    idx = N - 1, cnt = 0;
    while (str[idx] == 'B')
    {
        cnt++;
        idx--;
    }
    ans = min(ans, bCnt - cnt);
    cout << ans << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> str;
    solve();
    return 0;
}
