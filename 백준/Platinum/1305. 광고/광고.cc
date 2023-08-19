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
#include <sstream>
using namespace std;
#define INF 2000000000
typedef long long ll;

int L;
string str;
int failure[1000001];

void input(void)
{
    cin >> L >> str;
}

void solve(void)
{
    int j = 0;
    for (int i = 1; i < L; i++)
    {
        while (j > 0 && str[i] != str[j])
        {
            j = failure[j - 1];
        }
        if (str[i] == str[j])
            failure[i] = ++j;
    }
    cout << L - failure[L - 1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
