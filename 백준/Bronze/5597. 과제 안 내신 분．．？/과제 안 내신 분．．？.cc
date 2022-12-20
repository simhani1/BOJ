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
#define MAX 1000000007
typedef long long ll;

bool arr[31];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1, A; i <= 28; i++)
    {
        cin >> A;
        arr[A] = true;
    }
    for (int i = 1; i <= 30; i++)
    {
        if (!arr[i])
            cout << i << endl;
    }
    return 0;
}
