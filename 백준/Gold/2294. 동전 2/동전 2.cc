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
#define MAX 123456789
typedef long long ll;

int N, K;
int dp[100001];
set<int> coin;

int solve(void)
{
    fill(dp, dp + 100001, MAX);
    for (auto c : coin)
    {
        dp[c] = 1;
        for (int j = c + 1; j <= K; j++)
        {
            dp[j] = min(dp[j], dp[j - c] + 1);
        }
    }
    return dp[K] == MAX;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        coin.insert(X);
    }
    cout << (solve() ? -1 : dp[K]) << endl;
    return 0;
}
