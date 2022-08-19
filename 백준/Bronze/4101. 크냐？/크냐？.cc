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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        int A, B;
        cin >> A >> B;
        if (!A && !B)
            break;
        if (A > B)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
