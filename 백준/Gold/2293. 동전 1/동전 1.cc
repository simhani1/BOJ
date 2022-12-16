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
vector<int> coin;

int solve(void)
{
    for (auto c : coin)
    {
        dp[c]++;
        for (int j = c + 1; j <= K; j++)
            dp[j] += dp[j - c];
    }
    return dp[K];
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
        coin.push_back(X);
    }
    cout << solve() << endl;
    return 0;
}
