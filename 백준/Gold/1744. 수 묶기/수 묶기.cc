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

int N, cnt = 0;
priority_queue<int> p;
priority_queue<int, vector<int>, greater<int>> m;

ll solve(void)
{
    ll sum = 0;
    while (p.size() >= 2)
    {
        int A = p.top();
        p.pop();
        int B = p.top();
        p.pop();
        if (A == 1 || B == 1)
            sum += (A + B);
        else
            sum += (A * B);
    }
    while (m.size() >= 2)
    {
        int A = m.top();
        m.pop();
        int B = m.top();
        m.pop();
        sum += (A * B);
    }
    if (p.size() == 1 && m.size() == 0)
        sum += p.top();
    else if (p.size() == 1 && m.size() == 1)
    {
        if (cnt >= 1)
            sum += p.top();
        else
            sum += (p.top() + m.top());
    }
    else if (p.size() == 0 && m.size() == 1)
    {
        if (cnt == 0)
            sum += m.top();
    }
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
        if (X > 0)
            p.push(X);
        else if (X < 0)
            m.push(X);
        else
            cnt++;
    }
    cout << solve() << "\n";
    return 0;
}
