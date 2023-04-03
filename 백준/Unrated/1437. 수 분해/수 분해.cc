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

int N, ans = 1;

void solve(void)
{
    if (N == 0)
    {
        cout << 0 << "\n";
        return;
    }
    while (N > 4)
    {
        ans *= 3;
        ans %= 10007;
        N -= 3;
    }
    if (N != 0)
    {
        ans *= N;
        ans %= 10007;
    }
    cout << ans << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    solve();
    return 0;
}
