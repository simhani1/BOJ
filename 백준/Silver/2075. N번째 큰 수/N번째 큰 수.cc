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

int N, M;

priority_queue<int> pq;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> M;
            pq.push(-M);       // 일단 값을 넣으면 음수로 저장해서 작은 수가 앞에 오도록 저장
            if (pq.size() > N) // 만약 N번째 이후의 값을 입력받는다면 앞에서부터 작은 값들을 제거
                pq.pop();
        }
    }
    cout << -pq.top(); // 제일 큰 값이 top에 위치한다.
    return 0;
}
