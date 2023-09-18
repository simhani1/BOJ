#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;
#define INF 1e9
#define MOD 1000000
typedef long long ll;

string str = "WelcomeToSMUPC";
int N;

void input()
{
    cin >> N;
    int len = str.length();
    N--;
    N %= len;
    cout << str[N] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    return 0;
}
