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

int N;
char from, to;
string str;
bool arr[59][59];
vector<pair<char, char>> v;

int solve(void)
{
    for (int k = 0; k < 58; k++)
    {
        for (int i = 0; i < 58; i++)
        {
            for (int j = 0; j < 58; j++)
            {
                // 전건과 후건이 같은 경우는 포함시키지 않는다.
                if (i == j || i == k || k == j)
                    continue;
                if (arr[i][k] && arr[k][j])
                    arr[i][j] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 58; i++)
    {
        for (int j = 0; j < 58; j++)
        {
            if (i != j && arr[i][j])
            {
                ans++;
                v.push_back({i + 'A', j + 'A'});
            }
        }
    }
    sort(v.begin(), v.end());
    return ans;
}

// A: 65 - 65 = 0 Z: 90 - 65 = 25
// a: 97 - 65 = 32 z: 122 - 65 = 57

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0, A, B; i < N; i++)
    {
        cin >> from >> str >> to;
        A = from - 'A';
        B = to - 'A';
        arr[A][B] = true;
    }
    cout << solve() << "\n";
    for (auto i : v)
    {
        cout << i.first << " => " << i.second << "\n";
    }
    return 0;
}
