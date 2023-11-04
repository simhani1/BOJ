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
#define INF 2100000000
#define MOD 987654321
typedef long long ll;

int ans = 0;
string str;
vector<int> lk, rk;

void input(void)
{
    cin >> str;
}

void solve(void)
{
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'K')
            cnt++;
        else
            lk.push_back(cnt);
    }
    cnt = 0;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == 'K')
            cnt++;
        else
            rk.push_back(cnt);
    }
    reverse(rk.begin(), rk.end());
    int l = 0, r = lk.size() - 1;
    while (l <= r)
    {
        ans = max(ans, r - l + 1 + 2 * min(lk[l], rk[r]));
        if (lk[l] <= rk[r])
            l++;
        else
            r--;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
