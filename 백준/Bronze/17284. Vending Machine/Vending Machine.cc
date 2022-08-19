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

int N, ans = 5000;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> N)
    {
        if (N == 1)
            ans -= 500;
        else if (N == 2)
            ans -= 800;
        else if (N == 3)
            ans -= 1000;
    }
    cout << ans;
    return 0;
}
