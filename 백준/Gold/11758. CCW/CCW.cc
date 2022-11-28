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
#define MAX 1000000000000
typedef long long ll;

int X, Y;
int arr[2][3];
vector<pair<int, int>> v;

void solve(void)
{
    for (int i = 0; i < 2; i++)
    {
        arr[i][0] = v[i + 1].first - v[i].first;
        arr[i][1] = v[i + 1].second - v[i].second;
    }
    int Z = arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1];
    if (Z > 0)
        cout << 1 << endl;
    else if (Z < 0)
        cout << -1 << endl;
    else
        cout << 0 << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 3; i++)
    {
        cin >> X >> Y;
        v.push_back({X, Y});
    }
    solve();
    return 0;
}
