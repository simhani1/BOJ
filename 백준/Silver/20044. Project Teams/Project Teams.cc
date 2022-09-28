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

int N, ans = 1e9;
vector<int> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1, A; i <= 2 * N; i++)
    {
        cin >> A;
        v.push_back(A);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
    {
        ans = min(ans, v[i] + v[2 * N - 1 - i]);
    }
    cout << ans << endl;
    return 0;
}
