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

int N, M = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0, X; i < N; i++)
    {
        string str;
        cin >> str;
        if (str == "add")
        {
            cin >> X;
            M |= (1 << X);
        }
        else if (str == "remove")
        {
            cin >> X;
            M &= ~(1 << X);
        }
        else if (str == "check")
        {
            cin >> X;
            if (M & (1 << X))
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (str == "toggle")
        {
            cin >> X;
            if (M & (1 << X))
                M &= ~(1 << X);
            else
                M |= (1 << X);
        }
        else if (str == "all")
            M = (1 << 21) - 1;
        else if (str == "empty")
            M = 0;
    }
    return 0;
}
