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

int N, K, W, V;
int weight[101], value[101];
int dp[101][100001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    // 각 물건들의 무게 / 가치 저장
    for (int i = 1; i <= N; i++)
    {
        cin >> weight[i] >> value[i];
    }
    // 존재하는 물건들의 개수마다 각 무게 제한에 대한 최대 가치를 저장
    for (int product = 1; product <= N; product++)
    {
        for (int w = 0; w <= K; w++)
        {
            // 제한 무게보다 물건의 무게가 더 무거우면 가방에 넣을 수 없다
            // 따라서 그전가지의 물건들만 있을 때 얻는 최대 가치와 동일하다
            if (weight[product] > w)
                dp[product][w] = dp[product - 1][w];
            // 제한 무게보다 가벼워 담을 수 있는 경우
            // 넣지 않거나 또는 넣는 경우 중 최대 가치를 갖는 경우로 저장
            else if (weight[product] <= w)
                dp[product][w] = max(dp[product - 1][w], dp[product - 1][w - weight[product]] + value[product]);
        }
    }
    cout << dp[N][K];
    return 0;
}
