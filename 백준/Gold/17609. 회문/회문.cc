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
#define INF 123456789
typedef long long ll;

int T;
string str;

int solve(string str, int l, int r, int cnt)
{
    while (l < r)
    {
        if (str[l] == str[r])
        {
            l++;
            r--;
        }
        else
        {
            if (cnt == 0)
            {
                if (solve(str, l + 1, r, cnt + 1) == 0 || solve(str, l, r - 1, cnt + 1) == 0)
                    return 1;
                return 2;
            }
            else
                return 2;
        }
    }
    return 0;
}

void init(void)
{
    str.clear();
}

void input(void)
{
    cin >> T;
    while (T--)
    {
        init();
        cin >> str;
        cout << solve(str, 0, str.length() - 1, 0) << "\n";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    return 0;
}
