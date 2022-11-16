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

int N, sum = 0;
vector<int> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    v.push_back(1);
    sum += 1;
    for (int i = 3; i <= 100000; i += 2)
    {
        if (v.size() == N)
            break;
        sum += i;
        v.push_back(i);
        if (sum % v.size())
        {
            sum -= i;
            v.pop_back();
        }
    }
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}
