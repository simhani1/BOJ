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

string T, P;
vector<int> failure(1000000, 0), v;
int ans = 0;

void input(void)
{
    getline(cin, T);
    getline(cin, P);
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
        while (j > 0 && T[i] != P[j])
        {
            j = failure[j - 1];
        }
        if (T[i] == P[j])
        {
            if (j == P.size() - 1)
            {
                ans++;
                v.push_back(i - P.size() + 2); // 일치하는 인덱스
                j = failure[j];
            }
            else
                j++;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    makeFailure();
    kmp();
    cout << ans << "\n";
    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}
