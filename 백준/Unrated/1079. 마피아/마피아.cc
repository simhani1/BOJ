#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
#define INF 2147483648
typedef long long ll;

int N, killer, ans = 0;
int arr[17], R[17][17];
bool dead[17];

void dfs(int survive, int night)
{
    // 마피아만 생존하거나 마피아가 사망한 경우
    if (survive == 1 || dead[killer])
    {
        ans = max(ans, night);
        return;
    }
    // night
    if (survive % 2 == 0)
    {
        for (int i = 0; i < N; i++)
        {
            if (!dead[i] && i != killer)
            {
                dead[i] = true; // 사망
                for (int j = 0; j < N; j++)
                {
                    if (!dead[j])
                        arr[j] += R[i][j];
                }
                dfs(survive - 1, night + 1);
                for (int j = 0; j < N; j++)
                {
                    if (!dead[j])
                        arr[j] -= R[i][j];
                }
                dead[i] = false; // 부활
            }
        }
    }
    // day
    else
    {
        // 낮에 죽을 사람 선택
        int score = -9999;
        int idx = 9999;
        for (int i = 0; i < N; i++)
        {
            if (!dead[i])
            {
                if (arr[i] > score)
                {
                    score = arr[i];
                    idx = i;
                }
                else if (arr[i] == score)
                    idx = min(idx, i);
            }
        }
        dead[idx] = true;
        dfs(survive - 1, night);
        dead[idx] = false;
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
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> R[i][j];
        }
    }
    cin >> killer;
    dfs(N, 0);
    cout << ans << "\n";
    return 0;
}
