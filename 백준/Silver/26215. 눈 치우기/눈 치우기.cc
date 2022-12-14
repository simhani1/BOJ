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
#define MAX 123456789
typedef long long ll;

int N;
priority_queue<int> q;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0, A; i < N; i++)
    {
        cin >> A;
        q.push(A);
    }
    int curHouse = 0, ans = 0;
    while (!q.empty())
    {
        if (curHouse == 0)
        {
            curHouse = q.top();
            q.pop();
        }
        else
        {
            int nextHouse = q.top();
            q.pop();
            if (curHouse < nextHouse)
            {
                nextHouse -= curHouse;
                ans += curHouse;
                q.push(nextHouse);
                curHouse = 0;
            }
            else
            {
                curHouse -= nextHouse;
                ans += nextHouse;
                q.push(curHouse);
                curHouse = 0;
            }
        }
    }
    ans += curHouse;
    if (ans > 1440)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
