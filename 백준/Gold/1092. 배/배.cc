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

int N, M, maxLimit = 0, maxWeight = 0;
vector<int> crain, box;

int solve(void)
{
    int cnt = 0;
    while (!box.empty())
    {
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = box.size() - 1; j >= 0; j--)
            {
                if (crain[i] >= box[j])
                {
                    /*
                     반례
                     3
                     10 7 4
                     9
                     9 9 8 7 6 6 5 5 2
                     pop_back()을 사용할 경우 중간에 무게가 더 적은 박스가 사라지는 상황이 연출되지 않는다.
                     따라서 특정 박스를 지정하여 삭제시켜야 한다.
                */
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
        cnt++;
    }
    return cnt;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        maxLimit = max(maxLimit, X);
        crain.push_back(X);
    }
    cin >> M;
    for (int i = 0, X; i < M; i++)
    {
        cin >> X;
        maxWeight = max(maxWeight, X);
        box.push_back(X);
    }
    sort(crain.begin(), crain.end());
    sort(box.begin(), box.end());
    if (maxWeight > maxLimit)
        cout << -1 << "\n";
    else
        cout << solve() << "\n";
    return 0;
}
