#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
#define INF 123456789
typedef long long ll;

int N;

/*
    시작공백: i
    가운데 공백: (2*N - 3) - 2 * i
    별과 별 사이 공백: N-2

    머리 + 허리 = N개
    다리 = N - 1개

    i값을 N - 2부터 0까지 진행
*/

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        if (i == 0)
        {
            for (int j = 0; j < N; j++)
            {
                cout << "*";
            }
        }
        else
        {
            cout << "*";
            for (int j = 0; j < N - 2; j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        for (int j = 0; j < ((2 * N - 3) - 2 * i); j++)
        {
            cout << " ";
        }
        if (i == 0)
        {
            for (int j = 0; j < N; j++)
            {
                cout << "*";
            }
        }
        else
        {
            if (i != N - 1)
            {
                cout << "*";
            }
            for (int j = 0; j < N - 2; j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        if (i == 0)
        {
            for (int j = 0; j < N; j++)
            {
                cout << "*";
            }
        }
        else
        {
            cout << "*";
            for (int j = 0; j < N - 2; j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        for (int j = 0; j < ((2 * N - 3) - 2 * i); j++)
        {
            cout << " ";
        }
        if (i == 0)
        {
            for (int j = 0; j < N; j++)
            {
                cout << "*";
            }
        }
        else
        {
            cout << "*";
            for (int j = 0; j < N - 2; j++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
