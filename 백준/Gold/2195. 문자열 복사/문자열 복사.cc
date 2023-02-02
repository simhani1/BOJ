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

string S, P;
set<string> s;

bool check(string target, int length)
{
    bool flag;
    for (int i = 0; i < S.length(); i++)
    {
        flag = true;
        for (int j = i, idx = 0; j < i + length; j++, idx++)
        {
            if (S[j] != target[idx])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            break;
    }
    return flag;
}

int solve(void)
{
    int leftP = 0, rightP = 0, ans = 1;
    string tmp;
    while (rightP != P.length())
    {
        tmp.push_back(P[rightP]);
        if (check(tmp, rightP - leftP + 1))
            rightP++;
        else
        {
            leftP = rightP;
            ans++;
            tmp.clear();
        }
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> S >> P;
    cout << solve() << "\n";
    return 0;
}
