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
#define MAX 1000000007
typedef long long ll;

int N;
int dp[31];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    dp[2] = 3;
    dp[4] = dp[2] * 3 + 2;
    for (int i = 6; i <= N; i += 2)
    {
        dp[i] += (dp[i - 2] * 3 + 2);
        for (int j = 2; j <= i - 4; j += 2)
        {
            dp[i] += dp[j] * 2;
        }
    }
    cout << dp[N] << endl;
    return 0;
}
