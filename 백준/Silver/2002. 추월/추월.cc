#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 1234567890
typedef long long ll;

int N;
queue<string> A, B;
map<string, bool> m;

void input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        A.push(str);
        m[str] = false;
    }
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        B.push(str);
    }
}

void solve(void)
{
    int cnt = 0;
    while (!A.empty())
    {
        string now = A.front();
        string target = B.front();
        if (m[now])
        {
            A.pop();
            continue;
        }
        if (now == target)
            A.pop();
        else
        {
            cnt++;
            m[target] = true;
        }
        B.pop();
    }
    cout << cnt << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
