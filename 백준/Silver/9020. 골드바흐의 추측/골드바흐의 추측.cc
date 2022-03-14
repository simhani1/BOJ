#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <map>

using namespace std;

int T, n;
bool arr[10001];
vector <pair<int, int>> v;
int p, q;

//n이하의 소수들을 체크
void prime_num(int x) {
    for (int i = 2; i <= x; i++) {
        //소수일 경우
        if (arr[i]) {
            //배수들을 모두 false로 처리
            for (int j = i + i; j <= x; j += i) {
                arr[j] = false;
            }
        }
    }
}

void min_diff(void) {
    p = v[0].first;
    q = v[0].second;
    int sub = abs(p - q);
    for (int i = 1; i < v.size(); i++) {
        if (abs(v[i].first - v[i].second) < sub) {
            p = v[i].first;
            q = v[i].second;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        memset(arr, 1, sizeof(arr));
        prime_num(n);
        for (int i = 2; i <= n / 2; i++) {
            //소수일 경우
            if (arr[i]) {
                int x = i;
                int y = n - i;
                //y가 소수일 경우
                if (y > 1 && arr[y])
                    v.push_back({ x,y });
            }
        }
        min_diff();  //두수의 조합 중 차이가 제일 적은 쌍 구하기
        cout << min(p, q) << " " << max(p, q) << '\n';
        v.erase(v.begin(), v.end());  //벡터 비워주기
    }
    return 0;
}