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
#define INF 2147483648
typedef long long ll;

int N, M, K;
int bSum = 0, pSum = 0;
int dp[101][301][301];
vector<pair<int, int>> v(101);

int solve(void)
{
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= M; i++)
        {
            for (int j = 1; j <= K; j++)
            {
                if (i >= v[k].first && j >= v[k].second)
                    dp[k][i][j] = max(dp[k - 1][i][j], dp[k - 1][i - v[k].first][j - v[k].second] + 1);
                else
                    dp[k][i][j] = dp[k - 1][i][j];
            }
        }
    }
    return dp[N][M][K];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 1, A, B; i <= N; i++)
    {
        cin >> A >> B;
        v[i] = make_pair(A, B);
    }
    cout << solve() << "\n";
    return 0;
}
