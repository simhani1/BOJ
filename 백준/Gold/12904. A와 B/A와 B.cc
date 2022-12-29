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
#define MAX 9223372036854775807
typedef long long ll;

int ans;
string S, T;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> S >> T;
    if (S.length() < T.length())
    {
        while (S.length() != T.length())
        {
            if (T[T.length() - 1] == 'A')
                T.pop_back();
            else
            {
                T.pop_back();
                reverse(T.begin(), T.end());
            }
        }
    }
    if (S == T)
        ans = 1;
    else
        ans = 0;
    cout << ans << "\n";
    return 0;
}
