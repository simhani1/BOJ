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

int H, W, N;
vector<int> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> H >> W;
    for (int i = 0; i < W; i++)
    {
        cin >> N;
        v.push_back(N);
    }
    int left = 0, right = 1, sum = 0;
    // 왼쪽에서 오른쪽으로 진행
    while (right < W)
    {
        if (v[left] <= v[right])
        {
            for (int i = left; i < right; i++)
            {
                sum += v[left] - v[i];
            }
            left = right;
            right++;
        }
        else
            right++;
    }
    // 오른쪽에서 왼쪽으로 진행
    right = W - 1, left = W - 2;
    while (left >= 0)
    {
        if (v[right] < v[left]) // 왼쪽에서 오른쪽으로 진행하면서 높이가 같은 경우를 체크하기 때문에 등호를 빼줘야 한다. 중복이 발생한다.
        {
            for (int i = right; i > left; i--)
            {
                sum += v[right] - v[i];
            }
            right = left;
            left--;
        }
        else
            left--;
    }
    cout << sum;
    return 0;
}