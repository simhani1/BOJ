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
int arr[101][101];
queue<pair<int, int>> q;

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
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                q.push({i, j});
        }
    }
    //짝 홀
    if (q.front().first % 2 == 0 && q.front().second % 2 == 1)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i % 2 == 0 && j % 2 == 1)
                {
                    if (arr[i][j] == 1)
                    {
                        cout << "Kiriya";
                        return 0;
                    }
                }
                else if (i % 2 == 1 && j % 2 == 0)
                {
                    if (arr[i][j] == 1)
                    {
                        cout << "Kiriya";
                        return 0;
                    }
                }
            }
        }
        cout << "Lena";
    }
    // 짝 짝
    else if (q.front().first % 2 == 0 && q.front().second % 2 == 0)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i % 2 == 0 && j % 2 == 0)
                {
                    if (arr[i][j] == 1)
                    {
                        cout << "Kiriya";
                        return 0;
                    }
                }
                else if (i % 2 == 1 && j % 2 == 1)
                {
                    if (arr[i][j] == 1)
                    {
                        cout << "Kiriya";
                        return 0;
                    }
                }
            }
        }
        cout << "Lena";
    }
    // 홀 작
    else if (q.front().first % 2 == 1 && q.front().second % 2 == 0)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i % 2 == 0 && j % 2 == 1)
                {
                    if (arr[i][j] == 1)
                    {
                        cout << "Kiriya";
                        return 0;
                    }
                }
                else if (i % 2 == 1 && j % 2 == 0)
                {
                    if (arr[i][j] == 1)
                    {
                        cout << "Kiriya";
                        return 0;
                    }
                }
            }
        }
        cout << "Lena";
    }
    // 홀 홀
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i % 2 == 0 && j % 2 == 0)
                {
                    if (arr[i][j] == 1)
                    {
                        cout << "Kiriya";
                        return 0;
                    }
                }
                else if (i % 2 == 1 && j % 2 == 1)
                {
                    if (arr[i][j] == 1)
                    {
                        cout << "Kiriya";
                        return 0;
                    }
                }
            }
        }
        cout << "Lena";
    }
    return 0;
}
