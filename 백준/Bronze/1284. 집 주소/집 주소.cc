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

string str;
int arr[5];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        cin >> str;
        int ans = 2;
        ans += str.length() - 1;
        if (str == "0")
            break;
        for (int i = 0, num; i < str.length(); i++)
        {
            num = str[i] - '0';
            if (num == 1)
                ans += 2;
            else if (num == 0)
                ans += 4;
            else
                ans += 3;
        }
        cout << ans << "\n";
    }
    return 0;
}
