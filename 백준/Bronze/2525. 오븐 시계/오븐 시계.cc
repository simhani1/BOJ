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

int A, B, C;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B >> C;
    if ((B + C) >= 60)
    {
        A = (((B + C) / 60) + A) % 24;
        B = (B + C) % 60;
    }
    else
        B += C;
    cout << A << " " << B;
    return 0;
}