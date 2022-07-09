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

int S, N, K, X, Y, P, Q;

// 해당 좌표가 칠해져야 되는 범위에 속하는지 체크
int paint(int size, int x, int y)
{
    if (size == 1)
        return 0;
    int border = size / N;
    if (border * (N - K) / 2 <= x && x < border * (N + K) / 2 && border * (N - K) / 2 <= y && y < border * (N + K) / 2)
    {
        return 1;
    }
    return paint(border, x % border, y % border);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> S >> N >> K >> X >> P >> Y >> Q;
    if (S == 0)
    {
        cout << 0;
    }
    else
    {
        int size = pow(N, S);
        for (int i = X; i <= P; i++)
        {
            for (int j = Y; j <= Q; j++)
            {
                cout << paint(size, i, j);
            }
            cout << "\n";
        }
    }
    return 0;
}
