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

long long ans;
string A, B;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    for (int i = 0; i < A.length(); i++)
        for (int j = 0; j < B.length(); j++)
        {
            ans += (A[i] - '0') * (B[j] - '0');
        }
    cout << ans;
    return 0;
}
