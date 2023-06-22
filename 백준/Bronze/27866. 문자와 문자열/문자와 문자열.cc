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
#define INF 1234567890
typedef long long ll;

int N;
string str;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str >> N;
    cout << str[N - 1] << "\n";
    return 0;
}
