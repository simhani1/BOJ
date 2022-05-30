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
int vote[51];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> vote[i];
    }
    int ans = 0;
    int maxVote = 0;
    int maxCandidate = 1;
    while (true)
    {
        maxVote = 0;
        for (int i = 1; i <= N; i++)
        {
            // 최다 득표자 번호 찾기
            if (vote[i] >= vote[maxCandidate])
                maxCandidate = i;
        }
        // 최다 득표자가 1번일 경우 종료
        if (maxCandidate == 1)
            break;
        vote[1]++;
        vote[maxCandidate]--;
        ans++;
    }
    cout << ans;
    return 0;
}