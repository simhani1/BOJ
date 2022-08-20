#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N, T, C, P;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> T >> C >> P;
    int tmp = 1 + T;
    int cnt = 0;
    while (tmp <= N)
    {
        tmp += T;
        cnt++;
    }
    cout << cnt * C * P;
    return 0;
}
