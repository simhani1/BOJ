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

int N, A, price;
priority_queue<int> value;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> A;
        if (A == 0)
        {
            if (value.empty())
                cout << -1 << "\n";
            else
            {
                cout << value.top() << "\n";
                value.pop();
            }
        }
        else
        {
            for (int i = 0; i < A; i++)
            {
                cin >> price;
                value.push(price);
            }
        }
    }
    return 0;
}