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
int arr[26];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    fill(arr, arr + 26, -1);
    for (int i = 0; i < str.length(); i++)
    {
        if (arr[str[i] - 'a'] == -1)
            arr[str[i] - 'a'] = i;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
