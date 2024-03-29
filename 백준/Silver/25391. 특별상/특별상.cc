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

int N, M, K;
long long sum = 0;
priority_queue<pair<int, int>> pqA;
priority_queue<pair<int, int>> pqB;
// bool visited[1000000001];
set<int> s;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0, A, B; i < N; i++)
    {
        cin >> A >> B;
        pqA.push({A, B});
        pqB.push({B, A});
    }
    for (int i = 0; i < K; i++)
    {
        sum += pqB.top().second;
        s.insert(pqB.top().second);
        pqB.pop();
    }
    for (int i = 0; i < M; i++)
    {
        if (s.find(pqA.top().first) != s.end())
        {
            pqA.pop();
            i--;
        }
        else
        {
            sum += pqA.top().first;
            pqA.pop();
        }
    }
    cout << sum << endl;
    return 0;
}
