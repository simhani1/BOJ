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

int N, score, P;
int arr[51];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> score >> P;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int ans = 1, cnt = 0;
    for (int i = 0; i < N; i++)
    {
        // 입력받은 점수보다 큰 수의 개수만큼 등수가 밀린다
        if (score < arr[i])
            ans++;
        else if (score > arr[i])
            break;
        // 동점이 존재하는 경우 등수 유지
        cnt++;
    }
    // 리스트가 비어있는 경우 1등
    if (N == 0)
        ans = 1;
    // P개를 모두 검사한 경우 입력받은 점순는 진입 불가능
    if (cnt == P)
        ans = -1;
    cout << ans;
    return 0;
}
