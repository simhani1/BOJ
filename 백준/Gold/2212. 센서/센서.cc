#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 1234567890
typedef long long ll;

int N, K;
int arr[2000001];
vector<int> v;
priority_queue<int> pq;

void input(void)
{
    cin >> N >> K;
    for (int i = 0, A; i < N; i++)
    {
        cin >> A;
        arr[A + 1000000]++;
    }
}

void solve(void)
{
    for (int i = 0; i < 2000001; i++)
    {
        if (arr[i] == 0)
            continue;
        v.push_back(i - 1000000);
    }
    for (int i = 1; i < v.size(); i++)
    {
        pq.push(abs(v[i] - v[i - 1]));
    }
    int ans = 0;
    for (int i = 0; i < K - 1; i++)
    {
        if (pq.empty())
            break;
        pq.pop();
    }
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
