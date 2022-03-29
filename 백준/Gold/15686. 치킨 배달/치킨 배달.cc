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
typedef pair<int, int> pii;

int N, M;
int arr[50][50];
vector<pii> house;
vector <pii> chicken;
vector <pii> coordinate;
bool check[13];
int ans = 999999999;

int calcDistance(void) {
    int sum = 0;
    //모든 집 좌표에 대해서 M개의 치킨집 중 제일 가까운 거리들을 저장
    for (int i = 0; i < house.size(); i++) {
        int hx = house[i].first;
        int hy = house[i].second;
        int dist = 999999999;
        //선택된 M개의 치킨집과의 거리들을 구함
        for (int j = 0; j < coordinate.size(); j++) {
            int cx = coordinate[j].first;
            int cy = coordinate[j].second;
            dist = min(dist, abs(hx - cx) + abs(hy - cy));
        }
        sum += dist;
    }
    return sum;
}

void selectChicken(int idx, int cnt) {
    if (cnt == M) {
        ans = min(ans, calcDistance());
        return;
    }
    //치킨집 중 M개의 치킨집을 골라서 v벡터에 좌표 저장(조합)
    for (int i = idx; i < chicken.size(); i++) {
        if (!check[i]) {
            check[i] = true;
            coordinate.push_back(chicken[i]);
            selectChicken(i, cnt + 1);
            check[i] = false;
            coordinate.pop_back();
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
                house.push_back({ i,j });
            else if (arr[i][j] == 2)
                chicken.push_back({ i,j });
        }
    }
    selectChicken(0, 0);
    cout << ans;
    return 0;
}