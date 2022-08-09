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

int N;
int L[21], J[21];
int dp[21][101];

void solve(void)
{
    for (int person = 1; person <= N; person++)
    {
        // 소진한 체력에 대해서 얻는 기쁨을 저장
        for (int hp = 0; hp <= 100; hp++)
        {
            // 100을 모두 소진하는 경우 얻는 기쁨은 0
            if (hp == 100)
                dp[person][hp] = 0;
            else
            {
                if (L[person] <= hp)
                    dp[person][hp] = max(dp[person - 1][hp], dp[person - 1][hp - L[person]] + J[person]);
                else if (L[person] > hp)
                    dp[person][hp] = dp[person - 1][hp];
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == 0)
                cin >> L[j];
            else
                cin >> J[j];
        }
    }
    solve();
    // 체력 100을 모두 소진하면 기쁨이 0이므로 99체력을 소모했을 때의 기쁨이 최댓값
    cout << dp[N][99];
    return 0;
}
