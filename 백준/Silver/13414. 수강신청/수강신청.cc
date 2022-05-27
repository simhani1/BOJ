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

int K, L;
string id;
map<string, int> enroll; // id, cnt
map<int, string> ans;    // cnt, id

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> K >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> id;
        // ans에서 학번이 value이므로 중복이 될 수 있다
        // 따라서 최종적으로 하나의 인덱스 값만 갖도록 여러번 입력되는 id는 제거하고 갱신을 해줘야 한다
        if (enroll.find(id) != enroll.end())
            ans.erase(enroll[id]);
        enroll[id] = i;
        ans[i] = id;
    }
    int cnt = 0;
    for (map<int, string>::iterator i = ans.begin(); i != ans.end(); i++)
    {
        if (cnt == K)
            break;
        else
        {
            cout << i->second << "\n";
            cnt++;
        }
    }
    return 0;
}