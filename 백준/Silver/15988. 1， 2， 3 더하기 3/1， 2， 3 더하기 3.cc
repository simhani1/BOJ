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
#define DIVIDER 1000000009

int T, N;
long long dp[1000001] = {
    0,
    1,
    2,
    4,
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 4; i <= N; i++)
        {
            if (!dp[i])
                dp[i] += ((dp[i - 1] + dp[i - 2] + dp[i - 3]) % DIVIDER);
        }
        cout << dp[N] << endl;
    }
    return 0;
}
