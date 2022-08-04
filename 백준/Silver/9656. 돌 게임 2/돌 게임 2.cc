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
bool dp[1001];

bool game(int N)
{
    // 상근이 승리 == 1
    // 상근이 패배 == 0
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    for (int i = 4; i <= N; i++)
    {
        if (!dp[i - 1] || !dp[i - 3])
            dp[i] = true;
        else
            dp[i] = false;
    }
    return dp[N];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    if (game(N))
        cout << "SK";
    else
        cout << "CY";
    return 0;
}