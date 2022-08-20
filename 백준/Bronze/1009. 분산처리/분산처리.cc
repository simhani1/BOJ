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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0, A, B; i < N; i++)
    {
        cin >> A >> B;
        int tmp = A;
        for (int j = 1; j < B; j++)
        {
            tmp = (tmp * A) % 10;
        }
        if (tmp % 10 == 0)
            cout << 10 << endl;
        else
            cout << tmp % 10 << endl;
    }
    return 0;
}
