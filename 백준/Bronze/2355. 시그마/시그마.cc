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

using namespace std;
typedef long long ll;

ll A, B;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    ll ans;
    if (A < B)
        ans = (B * (B + 1) - A * (A - 1)) / 2;
    else if (A > B)
        ans = (A * (A + 1) - B * (B - 1)) / 2;
    else
        ans = A;
    cout << ans;
    return 0;
}