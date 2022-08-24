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

int N, K;

// N개 원판을 start 막대에서 goal 막대로 이동
void hanoi(int N, int start, int goal, int tmp)
{
    if (N == 1)
        cout << start << " " << goal << "\n";
    else
    {
        hanoi(N - 1, start, tmp, goal);
        cout << start << " " << goal << "\n";
        hanoi(N - 1, tmp, goal, start);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    cout << (int)pow(2, N) - 1 << "\n";
    hanoi(N, 1, 3, 2);
    return 0;
}
