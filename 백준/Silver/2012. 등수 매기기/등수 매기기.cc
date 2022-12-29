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
#define MAX 9223372036854775807
typedef long long ll;

int N;
ll sum = 0;
vector<int> v;

ll solve(void)
{
    for (int i = 0; i < v.size(); i++)
        sum += abs(i + 1 - v[i]);
    return sum;
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
    sort(v.begin(), v.end());
    cout << solve() << "\n";
    return 0;
}
