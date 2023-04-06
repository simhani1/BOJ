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

int N, B;
ll C, arr[1000001], cnt = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin >> B >> C;
    for (int i = 0; i < N; i++)
    {
        arr[i] -= B;
        cnt++;
    }
    for (int i = 0; i < N; i++)
    {
        if (0 < arr[i] && arr[i] <= C)
            cnt++;
        else if (arr[i] > C)
        {
            if (arr[i] % C != 0)
                cnt += (arr[i] / C + 1);
            else
                cnt += (arr[i] / C);
        }
    }
    cout << cnt << "\n";
    return 0;
}
