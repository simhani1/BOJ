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

int N, M, A;
long long ans = 0;
priority_queue<long long, vector<long long>, greater<long long> > card;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    while (N--)
    {
        cin >> A;
        card.push(A);
    }
    while (M--)
    {
        long long X = card.top();
        card.pop();
        long long Y = card.top();
        card.pop();
        for (int i = 0; i < 2; i++)
        {
            card.push(X + Y);
        }
    }
    while (!card.empty())
    {
        ans += card.top();
        card.pop();
    }
    cout << ans;
    return 0;
}