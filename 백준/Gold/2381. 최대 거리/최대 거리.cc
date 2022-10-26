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
vector<int> v1, v2;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    /**
     * |A-C| + |B-D|
     * A<=C라면
     * 1. (C+D)-(A+B)
     * 2. (C-D)-(A-B)
     * 둘 중 큰 값이 정답
     */
    for (int i = 0, A, B; i < N; i++)
    {
        cin >> A >> B;
        v1.push_back(A + B);
        v2.push_back(A - B);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    cout << max(v1[N - 1] - v1[0], v2[N - 1] - v2[0]) << endl;
    return 0;
}