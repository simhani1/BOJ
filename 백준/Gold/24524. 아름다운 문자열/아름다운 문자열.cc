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

string S, T, tmp;
int cnt = 0;
int dp[27];

void solve(void)
{
    for (int i = 0; i < S.length(); i++)
    {
        for (int j = 0; j < T.length(); j++)
        {
            if (S[i] == T[j])
            {
                if (j == 0)
                    dp[j]++;
                else
                {
                    if (dp[j - 1] > 0)
                    {
                        dp[j - 1]--;
                        dp[j]++;
                    }
                }
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> S >> T;
    solve();
    cout << dp[T.length() - 1] << endl;
    return 0;
}
