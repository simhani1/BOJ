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
vector<string> v;
ll ten[11] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000}, number[27];
priority_queue<ll> pq;

ll solve(void)
{
    ll ans = 0;
    ll cnt = 9;
    for (auto str : v)
    {
        for (int i = 0; i < str.size(); i++)
        {
            number[str[i] - 'A'] += ten[str.size() - i - 1];
        }
    }
    for (int i = 0; i < 27; i++)
    {
        if (number[i] != 0)
            pq.push(number[i]);
    }
    while (!pq.empty())
    {
        ans += (pq.top() * cnt--);
        pq.pop();
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    while (N--)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    cout << solve() << "\n";
    return 0;
}
