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

int N, M, cnt;
int member, memberCnt;
int parent[51];
vector<int> party[51];
vector<int> whoKnowTruth;

int Find(int A)
{
    if (A == parent[A])
        return A;
    return parent[A] = Find(parent[A]);
}

void Union(int A, int B)
{
    A = Find(A);
    B = Find(B);
    parent[B] = A;
}

void makeUnion(void)
{
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    //각 파티에 참여하는 사람들을 한 집합으로 묶어놓기
    for (int i = 1; i <= M; i++)
    {
        int mainMember = party[i][0];
        for (int j = 0; j < party[i].size(); j++)
        {
            int subMember = party[i][j];
            Union(mainMember, subMember);
        }
    }
}

void solve(void)
{
    int ans = 0;
    //각 파티마다 진실을 아는 사람이 있는지 체크 후 갈 수 있는 파티수를 구하기
    for (int i = 1; i <= M; i++)
    {
        bool isOk = true;
        for (int j = 0; j < party[i].size(); j++)
        {
            if (!isOk)
                break;
            int nowMember = party[i][j];
            for (int k = 0; k < cnt; k++)
            {
                //파티에 참여하는 사람과 진실을 아는 사람이 한명이라도 같은 집합에 속하면 해당 파티 참여 불가능
                if (Find(nowMember) == Find(whoKnowTruth[k]))
                {
                    isOk = false;
                    break;
                }
            }
        }
        //참여 가능한 경우
        if (isOk)
            ans++;
    }
    cout << ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    cin >> cnt;
    //진실을 알고 있는 사람들을 저장
    for (int i = 0; i < cnt; i++)
    {
        cin >> member;
        whoKnowTruth.push_back(member);
    }
    //각 파티마다 참가하는 사람들 입력
    for (int i = 1; i <= M; i++)
    {
        cin >> memberCnt;
        for (int j = 0; j < memberCnt; j++)
        {
            cin >> member;
            party[i].push_back(member);
        }
    }
    makeUnion();
    solve();
    return 0;
}