#define _CRT_SECURE_NO_WARNINGS
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
using namespace std;
#define INF 2000000000
#define MOD 1000000
typedef long long ll;

int N;
int arr[1001], dp[1001];
vector<int> lis;

void solve(void)
{
    vector<int> ans;
    int maxLen = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxLen = max(maxLen, dp[i]);
    }
    cout << maxLen << "\n";
    for (int i = N - 1; i >= 0; i--)
    {
        if (dp[i] == maxLen)
        {
            ans.push_back(arr[i]);
            maxLen--;
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
}

void input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
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
