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
#define INF 2147483648
typedef long long ll;

int C, N;
int dp[100001];
vector<pair<int, int>> v;

int solve(void)
{
    for (int i = 1; i <= 100000; i++)
    {
        for (auto j : v)
        {
            if (!i % j.first)
                dp[i] = max(dp[i], (i / j.first) * j.second);
            if (i - j.first >= 0)
                dp[i] = max(dp[i], dp[i - j.first] + j.second);
        }
        if (dp[i] >= C)
            return i;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> C >> N;
    for (int i = 0, A, B; i < N; i++)
    {
        cin >> A >> B;
        v.push_back({A, B});
    }
    cout << solve() << "\n";
    return 0;
}
