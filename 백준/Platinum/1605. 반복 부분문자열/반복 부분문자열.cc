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
#include <sstream>
using namespace std;
#define INF 2000000000
#define MOD 100003
typedef long long ll;

int L, ans = 0;
string parent;
vector<ll> hashC;

void input(void)
{
    cin >> L >> parent;
}

bool check(int len)
{
    ll hashP = 0, pow = 1;
    vector<vector<int>> v(MOD);
    hashC.push_back(0);
    for (int i = 0; i < len; i++)
    {
        hashP = (hashP * 2 + parent[i] - 'a' + 1) % MOD;
        hashC.push_back(hashP);
        pow = pow * 2 % MOD;
    }
    v[hashP].push_back(len - 1);
    for (int i = len; i < L; i++)
    {
        hashC.push_back((hashC.back() * 2 + parent[i] - 'a' + 1) % MOD);
        ll tmp = hashC.back() - hashC[hashC.size() - len - 1] * pow;
        tmp %= MOD;
        if (tmp < 0)
            tmp += MOD;
        for (auto idx : v[tmp])
        {
            if (parent.compare(idx - len + 1, len, parent, i - len + 1, len) == 0)
                return true;
        }
        v[tmp].push_back(i);
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    int l = 1, r = L;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}
