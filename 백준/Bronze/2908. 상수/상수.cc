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

string str1, str2;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str1 >> str2;
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for (int i = 0; i < 3; i++)
    {
        if (str1[i] > str2[i])
        {
            cout << str1 << endl;
            break;
        }
        else if (str1[i] < str2[i])
        {
            cout << str2 << endl;
            break;
        }
    }
    return 0;
}
