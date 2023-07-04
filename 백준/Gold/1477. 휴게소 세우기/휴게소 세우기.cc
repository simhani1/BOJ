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

int N, M, L;
vector<int> v;

void input(void)
{
    cin >> N >> M >> L;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        v.push_back(X);
    }
    v.push_back(0);
    v.push_back(L);
    sort(v.begin(), v.end());
}

void solve(void)
{
    int l = 1, r = 1000;
    int ans = 0;
    while (l <= r)
    {
        int cnt = 0;
        int mid = (l + r) / 2;
        for (int i = 1; i < v.size(); i++)
        {
            cnt += (v[i] - v[i - 1] - 1) / mid;
        }
        if (cnt <= M)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
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
