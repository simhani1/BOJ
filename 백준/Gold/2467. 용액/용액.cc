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
#define MAX 2000000000
typedef long long ll;

int N;
vector<int> v;

void solve(void)
{
    int l = 0, r = N - 1;
    int pSum = MAX;
    int A, B;
    while (l < r)
    {
        int tmp = v[l] + v[r];
        if (abs(pSum) > abs(tmp))
        {
            pSum = tmp;
            A = v[l];
            B = v[r];
        }
        if (tmp < 0)
            l++;
        else if (tmp > 0)
            r--;
        else
            break;
    }
    cout << A << " " << B << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        v.push_back(X);
    }
    solve();
    return 0;
}
