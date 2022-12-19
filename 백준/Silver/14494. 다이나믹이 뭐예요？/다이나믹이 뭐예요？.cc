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

int N, M;
int dp[1001][1001];

void init(void)
{
    for (int i = 1; i <= 1000; i++)
    {
        dp[1][i] = 1;
        dp[i][1] = 1;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    init();
    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= M; j++)
        {
            dp[i][j] = ((dp[i][j - 1] + dp[i - 1][j - 1]) % MAX + dp[i - 1][j]) % MAX;
        }
    }
    cout << dp[N][M] << endl;
    return 0;
}
