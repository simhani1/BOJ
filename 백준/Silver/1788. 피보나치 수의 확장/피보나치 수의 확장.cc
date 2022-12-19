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
#define MAX 123456789
typedef long long ll;

int N;
int dp[1000001] = {
    0,
    1,
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 2; i <= abs(N); i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
    }
    if (N < 0)
    {
        if ((-N) % 2) // odd
            cout << 1 << endl;
        else
            cout << -1 << endl;
        cout << dp[-N] << endl;
    }
    else if (N > 0)
        cout << 1 << endl
             << dp[N] << endl;
    else
        cout << 0 << endl
             << dp[N] << endl;
    return 0;
}
