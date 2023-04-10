#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
#define INF 123456789
typedef long long ll;

string str1, str2;
vector<int> v, ans;
bool visited[11];

int makeStringToNum(string s)
{
    int ten = pow(10, s.size() - 1);
    int num = 0;
    for (auto i : s)
    {
        num += (ten * (i - '0'));
        ten /= 10;
    }
    return num;
}

void solve(int idx, string tmp)
{
    if (idx == str1.size())
    {
        if (tmp.size() > str2.size() || tmp[0] == '0')
            return;
        int C = makeStringToNum(tmp);
        ans.push_back(C);
        return;
    }
    for (int i = 0; i < str1.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            tmp.push_back(str1[i]);
            solve(idx + 1, tmp);
            visited[i] = false;
            tmp.pop_back();
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str1 >> str2;
    for (auto i : str1)
    {
        v.push_back(i - '0');
    }
    solve(0, "");
    int B = makeStringToNum(str2);
    int ansNum = -1;
    for (auto i : ans)
    {
        if (i < B)
            ansNum = max(ansNum, i);
    }
    cout << ansNum << endl;
    return 0;
}
