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

string str;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    sort(str.begin(), str.end(), greater<>());
    // 30의 배수라면 일의 자리는 0, 모든 자리 수 합이 3의 배수를 만족해야 한다.
    if (str[str.length() - 1] == '0')
    {
        int sum = 0;
        for (auto i : str)
        {
            sum += (i - '0');
        }
        if (sum % 3 == 0)
            cout << str << "\n";
        else
            cout << -1 << "\n";
    }
    else
        cout << -1 << "\n";
    return 0;
}
