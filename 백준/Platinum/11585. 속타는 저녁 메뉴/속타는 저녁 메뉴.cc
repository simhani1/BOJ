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

int N, ans = 0;
string T, P;
vector<int> failure(1000000, 0);

void input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char c;
        cin >> c;
        T.push_back(c);
    }
    for (int i = 0; i < N; i++)
    {
        char c;
        cin >> c;
        P.push_back(c);
    }
    for (int i = 0; i < N - 1; i++)
    {
        T.push_back(T[i]);
    }
}

void makeFailure(void)
{
    int j = 0;
    for (int i = 1; i < P.size(); i++)
    {
        while (j > 0 && P[i] != P[j])
        {
            j = failure[j - 1];
        }
        if (P[i] == P[j])
            failure[i] = ++j;
    }
}

void kmp(void)
{
    int j = 0;
    for (int i = 0; i < T.size(); i++)
    {
        if (j >= N)
            break;
        while (j > 0 && T[i] != P[j])
        {
            j = failure[j - 1];
        }
        if (T[i] == P[j])
        {
            if (j == P.size() - 1)
            {
                ans++;
                j = failure[j];
            }
            else
                j++;
        }
    }
}

int getGcd(int a, int b)
{
    if (b == 0)
        return a;
    return getGcd(b, a % b);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    makeFailure();
    kmp();
    int gcd = getGcd(N, ans);
    cout << ans / gcd << "/" << N / gcd << "\n";
    return 0;
}
