#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> v) {
    vector<int> answer(v.size(), -1);
    stack<int> st;
    for(int i=0;i<v.size();i++){
        int now = v[i];
        while(!st.empty() && now > v[st.top()]){
            answer[st.top()]=now;
            st.pop();
        }
        st.push(i);
    }
    return answer;
}