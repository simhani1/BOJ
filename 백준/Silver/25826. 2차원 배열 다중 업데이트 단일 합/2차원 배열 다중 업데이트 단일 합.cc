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
#define MAX 98765432198765
typedef long long ll;

int N, M;
ll arr[1001][1001], dp[1001][1001];

void check(int A, int B, int C, int D, int K)
{
    arr[A][B] += K;
    arr[C + 1][D + 1] += K;
    arr[C + 1][B] -= K;
    arr[A][D + 1] -= K;
}

ll calc(int A, int B, int C, int D)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            arr[i][j] += arr[i][j - 1];
        }
    }
    for (int j = 0; j < N; j++)
    {
        for (int i = 1; i < N; i++)
        {
            arr[i][j] += arr[i - 1][j];
        }
    }
    ll sum = 0;
    for (int i = A; i <= C; i++)
    {
        for (int j = B; j <= D; j++)
        {
            sum += (arr[i][j] + dp[i][j]);
        }
    }
    return sum;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> dp[i][j];
        }
    }
    for (int i = 0, type, A, B, C, D, K; i < M; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> A >> B >> C >> D >> K;
            check(A, B, C, D, K);
        }
        else
        {
            cin >> A >> B >> C >> D;
            cout << calc(A, B, C, D) << "\n";
        }
    }
    return 0;
}
