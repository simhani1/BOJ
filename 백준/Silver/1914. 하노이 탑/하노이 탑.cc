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

int N, K;

// N개 원판을 start 막대에서 goal 막대로 이동
void hanoi(int N, int start, int goal, int tmp)
{
    if (N == 1)
        cout << start << " " << goal << "\n";
    else
    {
        hanoi(N - 1, start, tmp, goal);
        cout << start << " " << goal << "\n";
        hanoi(N - 1, tmp, goal, start);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    // 2^100은 출력 가능한 범위를 초과하므로 문자열로 계산
    string ans = to_string(pow(2, N));
    int x = ans.find('.');  // 소수점의 인덱스값
    ans = ans.substr(0, x); // 정수부분 문자열 저장
    ans[ans.length() - 1] -= 1;
    cout << ans << "\n";
    if (N <= 20)
        hanoi(N, 1, 3, 2);
    return 0;
}
