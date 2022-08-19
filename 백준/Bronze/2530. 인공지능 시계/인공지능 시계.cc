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

int A, B, C, D;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B >> C >> D;
    C += D;
    while (C >= 60)
    {
        C -= 60;
        B++;
    }
    while (B >= 60)
    {
        B -= 60;
        A++;
    }
    while (A >= 24)
    {
        A -= 24;
    }
    cout << A << " " << B << " " << C;
    return 0;
}
