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

int A, B;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    if (A > 2)
        cout << "After";
    else if (A == 2)
    {
        if (B > 18)
            cout << "After";
        else if (B == 18)
            cout << "Special";
        else
            cout << "Before";
    }
    else
        cout << "Before";
    return 0;
}
