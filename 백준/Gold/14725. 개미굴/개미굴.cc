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
#define INF 2147483648
typedef long long ll;

struct Trie
{
    map<string, Trie *> m;

    Trie() {}

    ~Trie()
    {
        m.clear();
    }

    void insert(vector<string> v, int idx)
    {
        if (idx == v.size())
            return;
        string now = v[idx];
        // 해당 문자열이 이미 저장된 경우
        if (m.find(now) != m.end())
            m[now]->insert(v, idx + 1);
        else
        {
            Trie *trie = new Trie();
            m.insert({now, trie});
            m[now]->insert(v, idx + 1);
        }
    }

    void print(int idx)
    {
        for (auto i : m)
        {
            for (int i = 0; i < idx; i++)
                cout << "--";
            cout << i.first << "\n";
            i.second->print(idx + 1);
        }
    }
};

int N, K;
string str;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    Trie *root = new Trie();
    for (int i = 0; i < N; i++)
    {
        cin >> K;
        vector<string> v;
        for (int j = 0; j < K; j++)
        {
            cin >> str;
            v.push_back(str);
        }
        root->insert(v, 0);
    }
    root->print(0);
    return 0;
}
