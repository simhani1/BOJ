#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
#define INF 123456789
typedef long long ll;

int N;
priority_queue<pair<int, int>> pq;

void solve(void)
{
    int idx = 1e9;
    while (!pq.empty())
    {
        int t = pq.top().first;
        int d = pq.top().second;
        pq.pop();
        if (idx > t)
            idx = t - d;
        else
            idx -= d;
    }
    cout << idx << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0, A, B; i < N; i++)
    {
        cin >> A >> B;
        pq.push({B, A});
    }
    solve();
    return 0;
}
