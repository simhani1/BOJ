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
#define MAX 1000000000
typedef long long ll;

int N;
vector<pair<pair<int, int>, string>> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        v.push_back({{age, i}, name});
    }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i.first.first << " " << i.second << "\n";
    }
    return 0;
}
