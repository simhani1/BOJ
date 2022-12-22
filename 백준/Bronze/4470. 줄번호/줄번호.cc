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
#define MAX 1000000007
typedef long long ll;

int N;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    cin.ignore(); // cin버퍼의 개행문자 삭제
    string str;
    for (int i = 0; i < N; i++)
    {
        getline(cin, str);
        cout << i + 1 << ". " << str << "\n";
        cin.clear(); // cin의 오류비트 제거
    }
    return 0;
}
