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

using namespace std;

int N, M;
int A, B;
int arr[100001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    while (M--)
    {
        cin >> A >> B;
        arr[A]++;
        arr[B]++;
    }
    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}