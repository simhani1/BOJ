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

int T;

void input(void)
{
    cin >> T;
    while (T--)
    {
        string str, ans;
        cin >> str;
        ans = str;
        int cnt = 0;
        while (next_permutation(str.begin(), str.end()))
        {
            cnt++;
            if (cnt == 2)
                break;
            ans = str;
        }
        cout << ans << "\n";
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
