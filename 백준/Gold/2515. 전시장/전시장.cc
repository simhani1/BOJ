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

int N, S, ans = 0;
vector<pair<int, int>> v;
int dp[300001];

int solve(void)
{
    int idx = 0, maxValue = 0, ans = 0;
    dp[0] = v[0].second;
    for (int i = 0; i < N; i++)
    {
        // 현재 그림의 높이와 차이가 S이상인 그림이 존재한다면 해당 그림의 인덱스를 저장 & 그 중 최대 이익 저장
        while (v[i].first - v[idx].first >= S)
        {
            maxValue = max(maxValue, dp[idx]);
            idx++;
        }
        dp[i] = v[i].second + maxValue;
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> S;
    for (int i = 0, H, C; i < N; i++)
    {
        cin >> H >> C;
        v.push_back({H, C});
    }
    sort(v.begin(), v.end());
    cout << solve() << endl;
    return 0;
}
