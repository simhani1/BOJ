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
#define MAX 1000001

int N;
string str;
bool flag;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    if (N == 0)
        cout << 0 << endl;
    else if (N < 0)
    {
        flag = true;
        N *= -1;
    }
    while (N)
    {
        int tmp = N % 3;
        if (tmp == 0)
            str += '0';
        else if (tmp == 1)
            str += '1';
        else
        {
            str += 'T';
            N++;
        }
        N /= 3;
    }
    if (!flag)
    {
        for (int i = str.size() - 1; i >= 0; i--)
        {
            cout << str[i];
        }
    }
    else
    {
        for (int i = str.size() - 1; i >= 0; i--)
        {
            if (str[i] == 'T')
                cout << 1;
            else if (str[i] == '1')
                cout << 'T';
            else
                cout << 0;
        }
    }
    return 0;
}
