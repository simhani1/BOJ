#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        bool isReverse = false;
        bool check = false;
        deque <int> ans;
        string str;
        string code;
        int n;
        cin >> code >> n >> str;
        //deque에 배열 원소 삽입
        int i = 0;
        while (str[i] != '\0') {
            //정수형으로 변환해서 저장(0~100사이 정수)
            int num = 0;
            while ('0' <= str[i] && str[i] <= '9') {
                num += str[i] - '0';
                num *= 10;
                i++;
            }
            if (num != 0)
                ans.push_back(num / 10);
            i++;
        }
        //명령 실행
        i = 0;
        while (code[i] != '\0') {
            if (code[i] == 'R')
                isReverse = !isReverse;
            else if (code[i] == 'D') {
                //비어 있지 않을 경우 원소 삭제
                if (!ans.empty()) {
                    //뒤집지 않을 경우
                    if (!isReverse)
                        ans.pop_front();
                    //뒤집을 경우
                    else
                        ans.pop_back();
                }
                //삭제할 원소가 없어서 error인 경우
                else {
                    cout << "error" << endl;
                    check = true;
                    break;
                }
            }
            i++;
        }
        //비어있지 않을 경우 출력
        if (!check) {
            cout << '[';
            //뒤집지 않을 경우
            if (!isReverse) {
                while (!ans.empty()) {
                    if (ans.size() == 1) {
                        cout << ans.front();
                        ans.pop_front();
                        break;
                    }
                    cout << ans.front() << ',';
                    ans.pop_front();
                }
            }
            //뒤집을 경우
            else {
                while (!ans.empty()) {
                    if (ans.size() == 1) {
                        cout << ans.back();
                        ans.pop_back();
                        break;
                    }
                    cout << ans.back() << ',';
                    ans.pop_back();
                }
            }
            cout << ']' << endl;
        }
    }
    return 0;
}