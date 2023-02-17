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

int N, M, O, remember = 0;
char X;
int arr[10001];
string str;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < 26; i++)
    {
        remember += (1 << i);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < str.size(); j++)
        {
            // i번째 문자열에 존재하는 단어들을 arr[i]에 저장
            arr[i] |= (1 << (str[j] - 'a'));
        }
    }
    for (int i = 0; i < M; i++)
    {
        cin >> O >> X;
        int ans = 0;
        // XOR 연산을 통해 현재 기억하고 있는 문자들을 저장
        remember ^= (1 << (X - 'a'));
        /**
         * 현재 기억하고 있는 문자 abc = 111
         * abd = 1011
         * 0111 & 1011 = 0011
         * 즉 abd는 외우지 못함
         * abc = 111
         * 111 & 111 = 111
         * 즉 abc는 외울 수 있음
         */
        for (int j = 0; j < N; j++)
        {
            if (arr[j] == (arr[j] & remember))
                ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
