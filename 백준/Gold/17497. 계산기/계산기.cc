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
#define INF 987654321
#define INIT 100000000
typedef long long ll;

ll N;
stack<char> st;

void solve(void)
{
    while (N)
    {
        if (N & 1)
        {
            N *= 2;
            st.push('/');
        }
        else if (N & 2)
        {
            N -= 2;
            st.push('+');
        }
        else
        {
            N /= 2;
            st.push('*');
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    solve();
    if (st.size() > 99)
        cout << -1 << "\n";
    else
    {
        cout << st.size() << "\n";
        while (!st.empty())
        {
            cout << "[" << st.top() << "] ";
            st.pop();
        }
    }
    return 0;
}
