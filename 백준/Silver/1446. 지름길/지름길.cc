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
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;

int N, D;
int dp[10001]; // i위치까지의 최소비용
vector<pii> v[10001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> D;
    for (int i = 0, A, B, C; i < N; i++)
    {
        cin >> A >> B >> C;
        if (B <= D && C <= B - A)  // 도착지보다 가깝고 실제로 지름길인 경우에 추가
        {
            v[B].push_back({A, C});
        }
    }
    fill(dp, dp + N, INF);
    dp[0] = 0;
    for (int i = 1; i <= D; i++)
    {
        dp[i] = dp[i - 1] + 1; 
        for (int j = 0; j < v[i].size(); j++)
        {
            dp[i] = min(dp[i], dp[v[i][j].first] + v[i][j].second);
        }
    }
    cout << dp[D] << endl;
    return 0;
}
