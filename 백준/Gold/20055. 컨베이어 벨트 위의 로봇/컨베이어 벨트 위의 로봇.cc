#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 2000000000
typedef long long ll;

int N, K;
deque<bool> conveyer;
deque<int> durability;

bool check(void)
{
    int cnt = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        if (!durability[i])
            cnt++;
    }
    return cnt < K;
}

void putRobot(void)
{
    if (!conveyer[0] && durability[0])
    {
        conveyer[0] = true;
        durability[0]--;
    }
}

void move(void)
{
    // 가장 먼저 올라간 로봇부터 이동한다.
    for (int i = N - 2; i >= 0; i--)
    {
        // 현재 칸에 로봇이 있고, 다음 칸에 로봇이 없고, 내구도가 1이상이면 이동
        if (conveyer[i] && !conveyer[i + 1] && durability[i + 1] >= 1)
        {
            conveyer[i] = false;
            conveyer[i + 1] = true;
            durability[i + 1]--;
        }
    }
    conveyer[N - 1] = false; // N-1번 칸에서 로봇이 내려간다.
}

void rotate(void)
{
    conveyer.push_front(conveyer.back());
    conveyer.pop_back();
    durability.push_front(durability.back());
    durability.pop_back();
    conveyer[N - 1] = false; // N-1번 칸에서 로봇이 내려간다.
}

void input(void)
{
    cin >> N >> K;
    for (int i = 0, X; i < 2 * N; i++)
    {
        cin >> X;
        conveyer.push_back(false);
        durability.push_back(X);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    int ans = 0;
    while (true)
    {
        ans++;
        rotate();
        move();
        putRobot();
        if (!check())
            break;
    }
    cout << ans << "\n";
    return 0;
}
