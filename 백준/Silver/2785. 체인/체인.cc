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

int N, sum = 0;
int arr[500001];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    for (int i = 1; i <= N; i++)
    {
        sum += arr[i];
        if (sum == N - i - 1)
            break;
        else if (sum > N - i - 1)
        {
            sum -= arr[i--];
            sum = N - i - 1;
            break;
        }
    }
    cout << sum << endl;
    return 0;
}
