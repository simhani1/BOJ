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
#define INF 123456789
#define MAX 2000000000
typedef long long ll;

int N, K, H;
vector<int> num, tree;

// ll query(int L, int R, int node, int nodeL, int nodeR){
//     if(L<=nodeL && nodeR<=R)
//         return tree[node];
//     if(nodeR < L || R < nodeL)
//         return 0;
//     int mid = (nodeL + nodeR)/2;
//     return query(L,R,node*2,nodeL, mid) + query(L,R,node*2+1, mid+1, nodeR);
// }
//
// void update(int idx){
//     idx+=(H-1);
//     tree[idx]++;
//     while(idx>1){
//         idx/=2;
//         tree[idx]=tree[idx*2]+tree[idx*2+1];
//     }
// }

int query(int L, int R, int node, int nodeL, int nodeR)
{
    if (L <= nodeL && nodeR <= R)
        return tree[node];
    if (nodeR < L || R < nodeL)
        return 1;
    int mid = (nodeL + nodeR) / 2;
    return query(L, R, node * 2, nodeL, mid) * query(L, R, node * 2 + 1, mid + 1, nodeR);
}

void update(int idx, int value)
{
    idx += H;
    if (value > 0)
        tree[idx] = 1;
    else if (value < 0)
        tree[idx] = -1;
    else
        tree[idx] = 0;
    while (idx > 1)
    {
        idx /= 2;
        tree[idx] = tree[idx * 2] * tree[idx * 2 + 1];
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> N >> K)
    {
        string ans;
        H = 1;
        while (N > H)
            H *= 2;
        tree.resize(2 * H);
        num.resize(N + 1);
        for (int i = 0; i < N; i++)
        {
            cin >> num[i];
            update(i, num[i]);
        }
        for (int i = 0, A, B; i < K; i++)
        {
            char command;
            cin >> command >> A >> B;
            if (command == 'C')
                update(A - 1, B);
            else
            {
                int result = query(A, B, 1, 1, H);
                if (result > 0)
                    ans += '+';
                else if (result < 0)
                    ans += '-';
                else
                    ans += '0';
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
