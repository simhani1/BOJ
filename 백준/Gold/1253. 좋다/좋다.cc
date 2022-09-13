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
vector<int> v;

int solve(void)
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int std = v[i];
        int l = 0, r = N - 1;
        while (l < r)
        {
            if (l == i)
            {
                l++;
                continue;
            }
            if (r == i)
            {
                r--;
                continue;
            }
            if (std > v[l] + v[r])
                l++;
            else if (std < v[l] + v[r])
                r--;
            else
            {
                if (l != r)
                {
                    cnt++;
                    break;
                }
            }
        }
    }
    return cnt;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0, A; i < N; i++)
    {
        cin >> A;
        v.push_back(A);
    }
    sort(v.begin(), v.end());
    cout << solve() << endl;
    return 0;
}
