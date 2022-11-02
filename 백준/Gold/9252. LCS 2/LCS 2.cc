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

string str1, str2, ans;
int dp[1001][1001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str1 >> str2;
    for (int i = 1; i <= str2.size(); i++)
    {
        for (int j = 1; j <= str1.size(); j++)
        {
            if (str2[i - 1] != str1[j - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            else
                dp[i][j] = dp[i - 1][j - 1] + 1;
        }
    }
    int now = dp[str2.size()][str1.size()], i = str2.size() + 1, j = str1.size() + 1;
    cout << now << endl;
    while (i > 0 && j > 0)
    {
        if (now == dp[i - 1][j])
            now = dp[--i][j];
        else if (now == dp[i][j - 1])
            now = dp[i][--j];
        else
        {
            ans.push_back(str2[i - 1]);
            now = dp[--i][--j];
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i;
    }
    return 0;
}
