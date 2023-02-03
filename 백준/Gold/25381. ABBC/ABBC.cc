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
#define INF 2147483648
typedef long long ll;

string str;
queue<int> A, B;

int solve(void)
{
    int ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'A')
            A.push(i);
        else if (str[i] == 'B')
            B.push(i);
        else
        {
            // C를 지우려면 B가 필요하고, A를 지우려면 B가 필요하므로 최대한 C부터 지우고 B를 최대한 지우는 방향으로
            if (!B.empty() && B.front() < i)
            {
                B.pop();
                ans++;
            }
        }
    }
    while (!A.empty() && !B.empty())
    {
        if (A.front() < B.front())
        {
            A.pop();
            B.pop();
            ans++;
        }
        else
            B.pop();
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    cout << solve() << "\n";
    return 0;
}
