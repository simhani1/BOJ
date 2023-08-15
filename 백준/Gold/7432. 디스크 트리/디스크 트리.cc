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
#include <sstream>
using namespace std;
#define INF 2000000000
typedef long long ll;

int N;

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
                cout << " ";
            cout << i.first << "\n";
            i.second->print(idx + 1);
        }
    }
};

vector<string> split(string s)
{
    istringstream ss(s);
    vector<string> v;
    string buffer;
    while (getline(ss, buffer, '\\'))
    {
        v.push_back(buffer);
    }
    return v;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    Trie *root = new Trie();
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        vector<string> v = split(str);
        root->insert(v, 0);
    }
    root->print(0);
    return 0;
}
