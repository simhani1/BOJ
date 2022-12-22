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
#define MAX 1000000007
typedef long long ll;

int L, N;
vector<int> v;

int solve(void)
{
    int cnt = 0;
    for (int i = 0; i < L; i++)
    {
        if (v[i] == N)
            return cnt;
    }
    v.push_back(N);
    sort(v.begin(), v.end());
    int l = N, r = N;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == N)
        {
            l = v[i - 1];
            r = v[i + 1];
        }
    }
    for (int i = l + 1; i <= N; i++)
    {
        if (i != N)
            cnt += (r - N);
        else
            cnt += (r - N - 1);
    }
    return cnt;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> L;
    for (int i = 0, K; i < L; i++)
    {
        cin >> K;
        v.push_back(K);
    }
    cin >> N;
    cout << solve() << endl;
    return 0;
}
