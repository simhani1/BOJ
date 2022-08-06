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

int N, M, K;
int check[4];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    while (K--)
    {
        int A, B;
        cin >> A >> B;
        if ((A + B) % 2 == 0 && A % 2 == 0)
            check[0] = true;
        else if ((A + B) % 2 == 0 && A % 2 == 1)
            check[1] = true;
        else if ((A + B) % 2 == 1 && A % 2 == 0)
            check[2] = true;
        else if ((A + B) % 2 == 1 && A % 2 == 1)
            check[3] = true;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!check[i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}