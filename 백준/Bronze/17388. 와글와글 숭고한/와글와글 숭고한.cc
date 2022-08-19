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

int arr[3], sum = 0, ans = 9999;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        ans = min(ans, arr[i]);
    }
    if (sum >= 100)
        cout << "OK";
    else
    {
        for (int i = 0; i < 3; i++)
        {
            if (arr[i] == ans)
            {
                if (i == 0)
                    cout << "Soongsil";
                else if (i == 1)
                    cout << "Korea";
                else
                    cout << "Hanyang";
            }
        }
    }
    return 0;
}
