#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 2000000000
typedef long long ll;

int N, M;
vector<string> v;
map<string, int> m;

void solve(void)
{
    while (M--)
    {
        string query;
        cin >> query;
        int num = 0;
        if ('0' <= query[0] && query[0] <= '9')
        {
            int ten = pow(10, query.length() - 1);
            for (int i = 0; i < query.length(); i++)
            {
                num += ((query[i] - '0') * ten);
                ten /= 10;
            }
            cout << v[num - 1] << "\n";
        }
        else
            cout << m[query] << "\n";
    }
}

void input(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
        m[str] = i + 1;
    }
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
