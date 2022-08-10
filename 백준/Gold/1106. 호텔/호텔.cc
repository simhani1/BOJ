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

int N, C;
int dp[100001]; // 각 홍보 비용에 대한 고객의 수를 저장, 최대 비용: 1000 * 100
vector<pair<int, int>> cost;

int solve(void)
{
    for (int price = 1; price <= 100000; price++)
    {
        for (int idx = 0; idx <= N; idx++)
        {
            // 도시의 홍보 비용 배수들을 초기화
            if (!price % cost[idx].first)
                dp[price] = max(dp[price], ((price / cost[idx].first) * cost[idx].second));
            // 여러 도시가 동시에 홍보하는 경우
            if (price - cost[idx].first >= 0)
                dp[price] = max(dp[price], dp[price - cost[idx].first] + cost[idx].second);
        }
        // 처음으로 목표 고객을 만족하는 비용을 반환
        if (dp[price] >= C)
            return price;
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
        cost.push_back({A, B});
    }
    cout << solve();
    return 0;
}
