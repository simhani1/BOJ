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

int N, M;
int minPack = 9999, minEach = 9999;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0, A, B; i < M; i++)
    {
        cin >> A >> B;
        minPack = min(minPack, A);
        minEach = min(minEach, B);
    }
    int cost = 0;
    while (N > 0)
    {
        if (N > 6)
        {
            if (6 * minEach > minPack)
                cost += minPack;
            else
                cost += 6 * minEach;
            N -= 6;
        }
        else
        {
            if (N * minEach > minPack)
                cost += minPack;
            else
                cost += N * minEach;
            N -= N;
        }
    }
    cout << cost;
    return 0;
}
