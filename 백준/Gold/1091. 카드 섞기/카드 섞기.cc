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
#define INF 2147483648
typedef long long ll;

int N;
int p[48], s[48], arr[48], card[48];

bool check(void)
{
    // i번째 카드가 원하는 플레이어에게 모두 갈 수 있는지 체크
    // 카드를 주는 규칙은 i번째 카드는 i%3번 플레이어게 가야하므로 해당 규칙을 작성해야 함
    for (int i = 0; i < N; i++)
    {
        if (i % 3 != p[card[i]])
            return false;
    }
    return true;
}

void shuffle(void)
{
    int tmp[48];
    // i번째 카드가 가야하는 위치에 현재 i번째 카드 번호를 임시로 저장
    for (int i = 0; i < N; i++)
        tmp[s[i]] = card[i];
    // 실제 카드 정보에 현재 i번째 위치에 있는 카드 번호를 갱신
    for (int i = 0; i < N; i++)
        card[i] = tmp[i];
}

bool isFinished(void)
{
    // 최초의 카드 상태로 돌아왔다면 절대로 만들 수 없는 것이다.
    for (int i = 0; i < N; i++)
    {
        if (i != card[i])
            return false;
    }
    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    // 0번째 카드 : p[0]플레이어에게 가야함...
    for (int i = 0; i < N; i++)
    {
        cin >> p[i]; // 각 카드가 어떤 플레이어에게 가야 하는지에 대한 정보
        card[i] = i; // 카드 최초 상태
    }
    // i번째 카드 : s[i]번째로 이동...
    for (int i = 0; i < N; i++)
    {
        cin >> s[i]; // 카드를 섞는 방법
    }
    int cnt = 0;
    while (true)
    {
        // 제일 처음에는 카드가 원상태 이므로 제외시켜야 한다.
        if (cnt != 0)
        {
            // 섞다보면 결국 처음 상태로 돌아올 것이다.
            // 이 경우 절대 원하는 대로 카드를 줄 수 없다.
            if (isFinished())
            {
                cout << -1 << endl;
                break;
            }
        }
        // 원하는 대로 카드를 줄 수 있는 경우
        if (check())
        {
            cout << cnt << endl;
            return 0;
        }
        shuffle();
        cnt++;
    }
    return 0;
}
