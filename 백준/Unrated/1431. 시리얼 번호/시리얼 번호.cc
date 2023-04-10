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
#define INF 123456789
typedef long long ll;

int N;
vector<pair<pair<int, int>, string>> v; // 길이, 숫자 총합, 문자열

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        int sum = 0;
        for (auto i : str)
        {
            if ('0' <= i && i <= '9')
                sum += (i - '0');
        }
        v.push_back({{str.size(), sum}, str});
    }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i.second << "\n";
    }
    return 0;
}
