#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;
#define INF 123456789
#define MOD 987654321
typedef long long ll;

int N, M;
bool dp[31][15001];
vector<int> v;

void dfs(int idx, int weight)
{
    if (idx > N || dp[idx][weight])
        return;
    dp[idx][weight] = true;
    dfs(idx + 1, weight - v[idx]);
    dfs(idx + 1, weight);
    dfs(idx + 1, weight + v[idx]);
}

void input(void)
{
    cin >> N;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        v.push_back(X);
    }
    dfs(0, 0);
    cin >> M;
    for (int i = 0, X; i < M; i++)
    {
        cin >> X;
        if (X > 15000)
            cout << "N ";
        else
            dp[N][X] ? cout << "Y " : cout << "N ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    return 0;
}
