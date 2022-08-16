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

int N;

void solve(int x, int y, int size)
{
    // 1*1 사각형의 경우 더이상 탐색이 불가능
    if (size == 1)
        cout << "*";
    else
    {
        // N*N 사각형의 중심 좌표인지 판단하는 식
        size /= 3;
        if ((x / size) % 3 == 1 && (y / size) % 3 == 1)
            cout << " ";
        else
            solve(x, y, size);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // 해당 좌표가 N*N 사각형의 중심인지 체크
            solve(i, j, N);
        }
        cout << "\n";
    }
    return 0;
}