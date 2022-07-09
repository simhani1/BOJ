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
double C, ans = 0;
double arr[11];
bool visited[11];

void pickCake(double sum, int idx)
{
    if (sum > 1.01)
        return;
    if (sum >= 0.99)
    {
        ans++;
        return;
    }
    for (int i = idx; i < N; i++)
    {
        // 재귀문으로 가능한 경우를 모두 탐색
        if (!visited[i])
        {
            visited[i] = true;
            pickCake(sum + arr[i], i + 1);
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> C;
        arr[i] = 1 / C; // 소수로 저장하기 위해서 C는 double형으로 지정해야 함
    }
    pickCake(0, 0);
    cout << ans;
    return 0;
}
