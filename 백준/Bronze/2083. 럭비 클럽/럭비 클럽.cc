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

string name;
int age, weight;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        cin >> name >> age >> weight;
        if (name == "#" && age == 0 && weight == 0)
            break;
        if (age > 17 || weight >= 80)
            cout << name << " Senior" << '\n';
        else
            cout << name << " Junior" << '\n';
    }
    return 0;
}
