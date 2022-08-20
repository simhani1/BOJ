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

int s1, s2, s3;
int arr[81];
int k = 0, v = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s1 >> s2 >> s3;

    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            for (int k = 1; k <= s3; k++)
            {
                arr[i + j + k]++;
                v = max(v, arr[i + j + k]);
            }
        }
    }
    for (int i = 3; i <= s1 + s2 + s3; i++)
    {
        if (v == arr[i])
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
