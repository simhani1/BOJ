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

string str;
int Q, L, R;
int arr[26][200001];
char A;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    for (int i = 1; i <= str.length(); i++)
    {
        if (i != 0)
        {
            for (int j = 0; j < 26; j++)
            {
                arr[j][i] += arr[j][i - 1];
            }
        }
        int character = str[i - 1] - 'a';
        arr[character][i]++;
    }
    cin >> Q;
    while (Q--)
    {
        cin >> A >> L >> R;
        R++;
        L++;
        cout << arr[A - 'a'][R] - arr[A - 'a'][L - 1] << "\n";
    }
    return 0;
}
