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

int K, X, Y;
int arr[10][10];
int cnt = 0;

bool check(int x, int y, int size)
{
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            // 해당 범위에 배수구나 타일이 있을 경우 패스
            if (arr[i][j] != 0)
            {
                return false;
            }
        }
    }
    // 아무것도 없을 경우 중앙쪽 모서리에 타일을 깔아야 함
    return true;
}

void tile(int x, int y, int size)
{
    if (size == 1)
        return;
    cnt++;
    int dividedSize = size / 2;
    // 1사분면
    if (check(x, y + dividedSize, dividedSize))
        arr[x + dividedSize - 1][y + dividedSize] = cnt;
    // 2사분면
    if (check(x, y, dividedSize))
        arr[x + dividedSize - 1][y + dividedSize - 1] = cnt;
    // 3사분면
    if (check(x + dividedSize, y, dividedSize))
        arr[x + dividedSize][y + dividedSize - 1] = cnt;
    // 4사분면
    if (check(x + dividedSize, y + dividedSize, dividedSize))
        arr[x + dividedSize][y + dividedSize] = cnt;

    tile(x, y + dividedSize, dividedSize);               // 1사분면
    tile(x, y, dividedSize);                             // 2사분면
    tile(x + dividedSize, y, dividedSize);               // 3사분면
    tile(x + dividedSize, y + dividedSize, dividedSize); // 4사분면
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> K >> X >> Y;
    int size = pow(2, K);
    // 좌표 변환
    arr[size + 1 - Y][X] = -1;
    // (1,1)부터 탐색 시작
    tile(1, 1, size);
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}