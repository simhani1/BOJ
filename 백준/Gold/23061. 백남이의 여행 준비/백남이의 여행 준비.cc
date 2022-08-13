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

int N, M, maxWeight = 0;
int W[101], V[101], B[101]; // 무게, 가치, 각 가방의 한계치
int dp[101][1000001];       // 무게마다 얻을 수 있는 최대 가치
double ans[101];            // 각 가방의 효율성

double solve(void)
{
    for (int product = 1; product <= N; product++)
    {
        for (int weight = 1; weight <= maxWeight; weight++)
        {
            if (W[product] > weight)
                dp[product][weight] = dp[product - 1][weight];
            else
                dp[product][weight] = max(dp[product - 1][weight], dp[product - 1][weight - W[product]] + V[product]);
        }
    }
    int std = 1;
    // 입력받은 각 가방의 효율성을 계산하고 최대 효울성의 가방 번호를 저장
    for (int i = 1; i <= M; i++)
    {
        ans[i] = (double)dp[N][B[i]] / (double)B[i];
        if (ans[i] > ans[std])
            std = i;
    }
    return std;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> W[i] >> V[i];
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> B[i];
        // 입력받은 가방 중 최대 무게까지에 대한 정보를 저장하면 나머지 무게에 대한 정보도 얻을 수 있다
        maxWeight = max(maxWeight, B[i]);
    }
    cout << solve();
    return 0;
}