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
#define INF 123456789
typedef long long ll;

int N, ans = INF;
string str1, str2;
int arr[100000], target[100000];

void init(void)
{
    for (int i = 0; i < N; i++)
    {
        arr[i] = str1[i] - '0';
    }
}

void change(int idx)
{
    if (idx == 0)
    {
        arr[idx] == 1 ? arr[idx] = 0 : arr[idx] = 1;
        arr[idx + 1] == 1 ? arr[idx + 1] = 0 : arr[idx + 1] = 1;
    }
    else if (idx == N - 1)
    {
        arr[idx - 1] == 1 ? arr[idx - 1] = 0 : arr[idx - 1] = 1;
        arr[idx] == 1 ? arr[idx] = 0 : arr[idx] = 1;
    }
    else
    {
        arr[idx - 1] == 1 ? arr[idx - 1] = 0 : arr[idx - 1] = 1;
        arr[idx] == 1 ? arr[idx] = 0 : arr[idx] = 1;
        arr[idx + 1] == 1 ? arr[idx + 1] = 0 : arr[idx + 1] = 1;
    }
}

bool check(int idx)
{
    if (arr[idx - 1] == target[idx - 1])
        return false;
    return true;
}

bool checkAns(void)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] != target[i])
            return false;
    }
    return true;
}

void solve(int start)
{
    int cnt = 0;
    if (start == 0)
    {
        change(start);
        cnt++;
    }
    for (int i = 1; i < N; i++)
    {
        if (check(i))
        {
            change(i);
            cnt++;
        }
    }
    if (checkAns())
        ans = min(ans, cnt);
}

void input(void)
{
    cin >> N;
    cin >> str1 >> str2;
    init();
    for (int i = 0; i < N; i++)
    {
        arr[i] = str1[i] - '0';
    }
    for (int i = 0; i < N; i++)
    {
        target[i] = str2[i] - '0';
    }
}

void printAns(void)
{
    if (ans == INF)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve(0);
    init();
    solve(1);
    printAns();
    return 0;
}
