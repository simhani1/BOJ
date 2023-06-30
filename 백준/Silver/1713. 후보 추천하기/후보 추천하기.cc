#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 1234567890
typedef long long ll;

int N, M;
int arr[101];
vector<pair<int, pair<int, int>>> v; // 사진 번호, 추천 횟수, 걸린 시간

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.second.first == b.second.first)
        return a.second.second < b.second.second;
    return a.second.first < b.second.first;
}

void input(void)
{
    cin >> N >> M;
    int t = 1;
    for (int i = 0, X; i < M; i++)
    {
        cin >> X;
        arr[X]++;
        if (v.size() < N)
        {
            // 처음 걸리는 경우
            if (arr[X] == 1)
                v.push_back({X, {1, t}});
            // 이미 걸려있는 경우
            else
            {
                for (int j = 0; j < v.size(); j++)
                {
                    // 같은 사진의 추천 횟수를 증가시켜주기
                    if (v[j].first == X)
                    {
                        v[j].second.first++;
                        break;
                    }
                }
            }
        }
        // 사진이 꽉 찬 경우
        else if (v.size() == N)
        {
            sort(v.begin(), v.end(), comp);
            // 현재 사진이 처음인 경우
            if (arr[X] == 1)
            {
                // 삭제된 사진 추천 수 초기화
                arr[v[0].first] = 0;
                v[0] = {X, {1, t}};
            }
            else
            {
                for (int j = 0; j < v.size(); j++)
                {
                    // 같은 사진의 추천 횟수를 증가시켜주기
                    if (v[j].first == X)
                    {
                        v[j].second.first++;
                        break;
                    }
                }
            }
        }
        t++;
    }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i.first << " ";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    return 0;
}
