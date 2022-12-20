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
#define MAX 1000000007
typedef long long ll;

string str;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    int q = str.length() / 10;
    int r = str.length() % 10;
    for (int i = 0; i < q; i++)
    {
        for (int j = i * 10; j < (i + 1) * 10; j++)
        {
            cout << str[j];
        }
        cout << endl;
    }
    for (int j = q * 10; j < q * 10 + r; j++)
    {
        cout << str[j];
    }
    cout << endl;
    return 0;
}
