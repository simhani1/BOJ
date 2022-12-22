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

int N;
ll sum = 0;
vector<int> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0, M; i < N; i++)
    {
        cin >> M;
        v.push_back(M);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
    {
        if (sum < v[i] - 1)
            break;
        else
            sum += v[i];
    }
    cout << sum + 1 << endl;
    return 0;
}
