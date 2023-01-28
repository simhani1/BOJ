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
#define MAX 123456789;
typedef long long ll;

int T, N, K;

bool check(int A, int B)
{
    int tmp1 = abs(K - A), tmp2 = abs(K - B);
    if (tmp1 > tmp2)
        return true;
    else if (tmp1 == tmp2 && A > B)
        return true;
    else
        return false;
}

int solve(int target, vector<int> &v)
{
    int l = 0, r = N * N - 1, tmp = MAX;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        // 제일 기준에 근접한 총합을 찾기 위한 함수
        // 더 근접한 총합이 나오는 경우 tmp에 갱신
        if (check(tmp, target + v[mid]))
            tmp = target + v[mid];
        if (target + v[mid] > K)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return tmp;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        int arr[4][1001], ans = MAX;
        vector<int> v1, v2;
        cin >> K >> N;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                // O(N^4)의 시간복잡도를 줄이기 위해 두개로 분할
                v1.push_back(arr[0][i] + arr[1][j]);
                v2.push_back(arr[2][i] + arr[3][j]);
            }
        }
        sort(v2.begin(), v2.end());
        // 벡터 하나를 돌면서 나머지 벡터에 대해 이분탐색을 진행하면 O(NlogN)의 시간복잡도로 해결이 가능하다.
        for (int i = 0; i < v1.size(); i++)
        {
            int tmp = solve(v1[i], v2);
            // 모든 몸무게에 대해서 계산을 할때마다 기준에 제일 근접한 정답을 갱신해 나간다.
            if (check(ans, tmp))
                ans = tmp;
        }
        cout << ans << "\n";
    }
    return 0;
}
