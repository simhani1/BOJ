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

int N;
string str;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> str;
        if (6 <= str.length() && str.length() <= 9)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
