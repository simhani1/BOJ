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
int arr[250001];

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
    int idx = 1;
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (arr[i] != idx)
            cnt++;
        else if (arr[i] == idx)
            idx++;
    }
    cout << cnt;
    return 0;
}