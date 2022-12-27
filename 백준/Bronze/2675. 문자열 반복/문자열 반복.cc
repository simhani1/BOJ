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

int T, R;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        string str;
        cin >> R;
        cin >> str;
        for (int i = 0; i < str.length(); i++)
        {
            for (int j = 0; j < R; j++)
            {
                cout << str[i];
            }
        }
        cout << endl;
    }
    return 0;
}
