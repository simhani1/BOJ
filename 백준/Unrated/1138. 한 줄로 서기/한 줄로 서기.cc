#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
#define INF 123456789
typedef long long ll;

int N, arr[11];
stack<int> st, tmp;

void solve(void)
{
    st.push(N - 1);
    for (int i = N - 2; i >= 0; i--)
    {
        int leftCnt = arr[i];
        while(leftCnt--)
        {
            tmp.push(st.top());
            st.pop();
        }
        st.push(i);
        while (!tmp.empty())
        {
            st.push(tmp.top());
            tmp.pop();
        }
    }
    while (!st.empty())
    {
        cout << st.top() + 1 << " ";
        st.pop();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    solve();
    return 0;
}
