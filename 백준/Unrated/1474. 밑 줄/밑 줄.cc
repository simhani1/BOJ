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
#define INF 2147483648
typedef long long ll;

int N, M, cnt = 0;
vector<string> v;
int underbar[10];
string str;

void solve(void)
{
    int q = (M - cnt) / (N - 1);
    int r = (M - cnt) % (N - 1);
    // 오름차순으로 만들어야 하므로 소문자에 대해 먼저 진행해야 함
    // 소문자인 경우 _를 앞쪽 단어부터 넣어야 함
    for (int i = 1; i < N; i++)
    {
        if (r > 0 && 'a' <= v[i][0] && v[i][0] <= 'z')
        {
            v[i] = '_' + v[i];
            r--;
        }
    }
    // 대문자의 경우 _를 뒤쪽 단어부터 넣어야 함
    for (int i = N - 1; i >= 0; i--)
    {
        if (r > 0 && 'A' <= v[i][0] && v[i][0] <= 'Z')
        {
            v[i] = '_' + v[i];
            r--;
        }
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < q; j++)
        {
            v[i] = '_' + v[i];
        }
    }
    for (auto i : v)
    {
        cout << i;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        cnt += tmp.length();
        v.push_back(tmp);
    }
    solve();
    return 0;
}
