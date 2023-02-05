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
int parent[30001], candy[30001], person[30001], dp[30001];

int Find(int X)
{
    if (parent[X] == X)
        return X;
    return parent[X] = Find(parent[X]);
}

void Union(int X, int Y)
{
    int pX = Find(X);
    int pY = Find(Y);
    parent[min(pX, pY)] = max(pX, pY);
}

int solve(void)
{
    for (int i = 1; i <= N; i++)
    {
        if (parent[i] != i)
        {
            int p = Find(i);
            candy[p] += candy[i];
            person[p] += person[i];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (parent[i] != i)
            continue;
        for (int j = K - 1; j - person[i] >= 0; j--)
        {
            dp[j] = max(dp[j], dp[j - person[i]] + candy[i]);
        }
    }
    return dp[K - 1];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> candy[i];
        person[i] = 1;
        parent[i] = i;
    }
    for (int i = 0, A, B; i < M; i++)
    {
        cin >> A >> B;
        Union(A, B);
    }
    cout << solve() << "\n";
    return 0;
}
