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
#define MAX 98765432198765
typedef long long ll;

int N;
vector<int> v;

int solve(void)
{
    sort(v.begin(), v.end());
    return v[(N - 1) / 2];
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
    cout << solve() << "\n";
    return 0;
}
