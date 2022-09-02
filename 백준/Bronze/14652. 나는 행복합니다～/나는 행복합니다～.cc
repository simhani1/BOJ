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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (cnt == K)
            {
                cout << i << " " << j;
            }
            cnt++;
        }

    return 0;
}