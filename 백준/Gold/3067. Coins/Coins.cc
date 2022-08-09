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

int T, N, M;
int dp[10001]; // 각 금액을 만드는 방법의 수를 저장
vector<int> C;

void solve(void)
{
    for (auto coin : C)
    {
        // base case
        dp[coin]++;
        for (int price = coin + 1; price <= M; price++)
        {
            dp[price] += dp[price - coin];
        }
    }
    cout << dp[M] << "\n";
    fill(dp, dp + 10001, 0);
    C.clear();
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0, P; i < N; i++)
        {
            cin >> P;
            C.push_back(P);
        }
        cin >> M;
        solve();
    }
    return 0;
}
