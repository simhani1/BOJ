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

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;
        if (str.length() == 1)
            cout << str << str << endl;
        else if (str.length() == 2)
            cout << str << endl;
        else
            cout << str[0] << str[str.length() - 1] << endl;
    }
    return 0;
}