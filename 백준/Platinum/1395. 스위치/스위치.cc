#include<iostream>
#include<vector>
#include<cmath>
 
#define endl "\n"
#define MAX 100010
using namespace std;
 
int N, M;
int Switch[MAX];
vector<int> SegmentTree;
vector<int> Lazy;
vector<pair<int, pair<int, int>>> Cmd;
 
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        Cmd.push_back(make_pair(a, make_pair(b, c)));
    }
}
 
void Lazy_Update(int Node, int Start, int End)
{
    if (Lazy[Node] != 0)
    {
        SegmentTree[Node] = (End - Start + 1) - SegmentTree[Node];
        if (Start != End)
        {
            Lazy[Node * 2] = !Lazy[Node * 2];
            Lazy[Node * 2 + 1] = !Lazy[Node * 2 + 1];
        }
        Lazy[Node] = 0;
    }
}
 
void Update(int Node, int Start, int End, int Left, int Right)
{
    Lazy_Update(Node, Start, End);
    if (Right < Start || Left > End) return;
    if (Left <= Start && End <= Right)
    {
        SegmentTree[Node] = (End - Start + 1) - SegmentTree[Node];
        if (Start != End)
        {
            Lazy[Node * 2] = !Lazy[Node * 2];
            Lazy[Node * 2 + 1] = !Lazy[Node * 2 + 1];
        }
        return;
    }
 
    int Mid = (Start + End) / 2;
    Update(Node * 2, Start, Mid, Left, Right);
    Update(Node * 2 + 1, Mid + 1, End, Left, Right);
    SegmentTree[Node] = SegmentTree[Node * 2] + SegmentTree[Node * 2 + 1];
}
 
int Query(int Node, int Start, int End, int Left, int Right)
{
    Lazy_Update(Node, Start, End);
    if (Right < Start || Left > End) return 0;
    if (Left <= Start && End <= Right) return SegmentTree[Node];
 
    int Mid = (Start + End) / 2;
    int Left_Result = Query(Node * 2, Start, Mid, Left, Right);
    int Right_Result = Query(Node * 2 + 1, Mid + 1, End, Left, Right);
    return Left_Result + Right_Result;
}
 
void Solution()
{
    int Tree_Height = (int)ceil(log2(N));
    int Tree_Size = 1 << (Tree_Height + 1);
    SegmentTree.resize(Tree_Size, 0);
    Lazy.resize(Tree_Size);
    
    for (int i = 0; i < M; i++)
    {
        int Command = Cmd[i].first;
        if (Command == 0)
        {
            int Index = Cmd[i].second.first - 1;
            int Index2 = Cmd[i].second.second - 1;
            Update(1, 0, N - 1, Index, Index2);
            continue;
        }
 
        int Index = Cmd[i].second.first - 1;
        int Index2 = Cmd[i].second.second - 1;
        cout << Query(1, 0, N - 1, Index, Index2) << endl;
    }
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
