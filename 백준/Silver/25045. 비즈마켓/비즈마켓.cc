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

int N, M, A, B;
priority_queue<int> client;
priority_queue<int, vector<int>, greater<int>> company;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> A;
        client.push(A);
    }
    for (int j = 0; j < M; j++)
    {
        cin >> B;
        company.push(B);
    }
    long long sum = 0;
    while (!client.empty() && !company.empty())
    {
        int a = client.top();
        int b = company.top();
        if (a - b < 0)
            break;
        sum += (a - b);
        client.pop();
        company.pop();
    }
    cout << sum;
    return 0;
}
