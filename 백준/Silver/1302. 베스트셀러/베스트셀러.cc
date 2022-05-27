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

using namespace std;

int N;
string str;
map<string, int> book;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        book[str]++;
        ans = max(ans, book[str]);
    }
    // iterator => 컨테이너에 저장된 원소들을 하나씩 주소를 저장할 수 있는 자료형
    // 화살표로 값에 접근한다.
    for (map<string, int>::iterator i = book.begin(); i != book.end(); i++)
    {
        if (ans == i->second)
        {
            cout << i->first;
            break;
        }
    }
    return 0;
}