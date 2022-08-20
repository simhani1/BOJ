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

int N, L, D;
bool song, bell;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> L >> D;
    for (int i = 0; i < (L + 5) * N; i++)
    {
        if (i % (L + 5) == 0)
            song = true;
        else if (i % (L + 5) == L)
            song = false;
        if (i % D == 0)
            bell = true;
        else if (i % D == 1)
            bell = false;
        if (!song && bell)
        {
            cout << i;
            return 0;
        }
    }
    for (int i = (L + 5) * N;; i++)
    {
        if (i % D == 0)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}
