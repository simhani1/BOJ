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

int N;
map<string, bool> history;
vector<string> member;
string name, type;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> name >> type;
        if (type == "enter")
            history[name] = true;
        else if (type == "leave")
            history[name] = false;
    }
    for (auto m : history)
    {
        // 회사에 남아있는 사람일 경우
        if (m.second)
            member.push_back(m.first);
    }
    // 내림차순 정렬
    sort(member.begin(), member.end(), greater<string>());
    for (string name : member)
    {
        cout << name << "\n";
    }
    return 0;
}
