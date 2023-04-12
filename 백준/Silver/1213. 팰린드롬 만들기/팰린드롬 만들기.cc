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

string str;
int arr[27];

string solve(void)
{
    int oddCnt = 0;
    string ans, tmp;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] % 2)
            oddCnt++;
    }
    if (str.size() % 2 == 0)
    {
        if (oddCnt)
            return "I'm Sorry Hansoo";
        for (int i = 0; i < 26; i++)
        {
            int halfCnt = arr[i] / 2;
            arr[i] -= halfCnt;
            while (halfCnt--)
                ans += (i + 'A');
        }
        for (int i = 25; i >= 0; i--)
        {
            while (arr[i]--)
                ans += (i + 'A');
        }
    }
    else
    {
        if (oddCnt >= 2)
            return "I'm Sorry Hansoo";
        char mid;
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] % 2)
            {
                mid = i + 'A';
                arr[i]--;
            }
            int halfCnt = arr[i] / 2;
            arr[i] -= halfCnt;
            while (halfCnt--)
                ans += (i + 'A');
        }
        ans += mid;
        for (int i = 25; i >= 0; i--)
        {
            while (arr[i]--)
                ans += (i + 'A');
        }
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    for (auto i : str)
    {
        arr[i - 'A']++;
    }
    cout << solve() << "\n";
    return 0;
}
