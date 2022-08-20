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

int A, B;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    int ans1 = -A - sqrt(A * A - B);
    int ans2 = -A + sqrt(A * A - B);
    if (ans1 == ans2)
        cout << ans1;
    else
        cout << ans1 << " " << ans2;
    return 0;
}
