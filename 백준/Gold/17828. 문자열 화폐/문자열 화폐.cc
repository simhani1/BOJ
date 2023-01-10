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

int N, X;
string str;

void solve(void)
{
    X -= N; // 기본으로 A로 가득 채울 수 있어야 함
    while (X >= 25)
    {
        str.push_back('Z');
        X -= 25;
    }
    if (X > 0)
        str.push_back('A' + X);
    int lenA = N - str.length();
    while (lenA--)
        str.push_back('A');
    reverse(str.begin(), str.end());
    cout << str << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> X;
    if (N * 26 < X || N > X)
        cout << "!\n";
    else
        solve();
    return 0;
}
