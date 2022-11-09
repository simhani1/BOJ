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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> N)
    {
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            string str;
            int tmp = 0;
            cin >> str;
            // 숙련도 계산
            for (int j = 0; j < str.size(); j++)
            {
                tmp |= (1 << (str[j] - '0')); // 추가하기
            }
            // 해당 숙련도가 존재하지 않으면 추가
            bool flag = false;
            for (int j = 0; j < v.size(); j++)
            {
                if (tmp == v[j])
                    flag = true;
            }
            if (!flag)
                v.push_back(tmp);
        }
        cout << v.size() << endl;
    }
    return 0;
}
