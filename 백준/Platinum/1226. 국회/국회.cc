#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;
#define INF 1e9
#define MOD 1000000
typedef long long ll;

int N, sum;
vector<pair<int, int>> v;
vector<int> dp[100001];

void solve()
{
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    sum /= 2;
    int maxSum = 0;
    dp[0].push_back(0);
    for (auto now : v)
    {
        for (int i = sum; i >= 0; i--)
        {
            if (!dp[i].empty() && dp[i + now.first].empty())
            {
                maxSum = max(maxSum, i + now.first);
                dp[i + now.first] = dp[i];
                dp[i + now.first].push_back(now.second);
            }
        }
    }
    sort(dp[maxSum].begin(), dp[maxSum].end());
    // 0을 처리하는 초기값 제외
    cout << dp[maxSum].size() - 1 << "\n";
    for (int i = 1; i < dp[maxSum].size(); i++)
    {
        cout << dp[maxSum][i] << " ";
    }
}

void input()
{
    cin >> N;
    for (int i = 1, X; i <= N; i++)
    {
        cin >> X;
        v.push_back({X, i});
        sum += X;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
