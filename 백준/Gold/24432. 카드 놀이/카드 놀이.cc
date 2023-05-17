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
#define INF 123456789
typedef long long ll;

int T, N, M, K;
vector<int> vB, vA, tmpB, tmpA, pSumB, pSumA;
bool visitedB[21], visitedA[21];

void input(void)
{
    cin >> N >> M >> K;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        vB.push_back(X);
    }
    for (int i = 0, X; i < M; i++)
    {
        cin >> X;
        vA.push_back(X);
    }
}

void init(void)
{
    vB.clear();
    vA.clear();
    pSumB.clear();
    pSumA.clear();
}

void combB(int idx, int cnt)
{
    if (cnt == K)
    {
        int sum = 0;
        for (int i : tmpB)
        {
            sum += i;
        }
        pSumB.push_back(sum);
    }
    for (int i = idx; i < N; i++)
    {
        if (!visitedB[i])
        {
            visitedB[i] = true;
            tmpB.push_back(vB[i]);
            combB(i + 1, cnt + 1);
            visitedB[i] = false;
            tmpB.pop_back();
        }
    }
}

void combA(int idx, int cnt)
{
    if (cnt == K)
    {
        int sum = 0;
        for (int i : tmpA)
        {
            sum += i;
        }
        pSumA.push_back(sum);
    }
    for (int i = idx; i < M; i++)
    {
        if (!visitedA[i])
        {
            visitedA[i] = true;
            tmpA.push_back(vA[i]);
            combA(i + 1, cnt + 1);
            visitedA[i] = false;
            tmpA.pop_back();
        }
    }
}

void solve(void)
{
    sort(pSumB.begin(), pSumB.end());
    sort(pSumA.begin(), pSumA.end());
    int minAns = INF, maxAns = 0;
    for (int i : pSumB)
    {
        maxAns = max(maxAns, max(abs(i - pSumA[0]), abs(i - pSumA[pSumA.size() - 1])));
        auto low = lower_bound(pSumA.begin(), pSumA.end(), i);
        int idx = low - pSumA.begin();
        if (idx == pSumA.size())
        {
            idx--;
            minAns = min(minAns, abs(i - pSumA[idx]));
        }
        else
            minAns = min(minAns, min(abs(i - pSumA[idx - 1]), abs(i - pSumA[idx])));
    }
    cout << minAns << " " << maxAns << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        init();
        input();
        combB(0, 0);
        combA(0, 0);
        solve();
    }
    return 0;
}
