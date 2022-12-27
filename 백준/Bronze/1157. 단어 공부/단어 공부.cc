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
#define MAX 1000000000
typedef long long ll;

int arr[26];
string str;
char ans;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a')
            arr[str[i] - 'a']++;
        else
            arr[str[i] - 'A']++;
    }
    int max = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == max && arr[i] != 0)
            ans = '?';
        if (arr[i] > max)
        {
            max = arr[i];
            ans = 'A' + i;
        }
    }
    cout << ans << endl;
    return 0;
}
