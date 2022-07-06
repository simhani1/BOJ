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
string name;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> name;
    switch (name[N - 1])
    {
    case 'q':
    case 'w':
    case 'e':
    case 'r':
    case 't':
    case 'a':
    case 's':
    case 'd':
    case 'f':
    case 'g':
    case 'z':
    case 'x':
    case 'c':
    case 'v':
        cout << "1";
        break;
    default:
        cout << "0";
        break;
    }
    return 0;
}
