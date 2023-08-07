#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

vector<vector<string>> v;
vector<pair<int, string>> inOutRecord;
map<string, string> userInfo;  // userId, name
vector<string> answer;

void debug(){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<endl;
        }
    }
}

void splitRecord(vector<string> record){
    for(int i=0;i<record.size();i++){   
        string cmd = record[i];
        istringstream ss(cmd);
        vector<string> str;
        string tmp;
        while(getline(ss, tmp, ' ')){
            str.push_back(tmp);
        }
        v.push_back(str);
    }
}

void solve(){
    for(int i=0;i<v.size();i++){
        string userId, name;
        // leave
        if(v[i].size() == 2){
            userId = v[i][1];
            inOutRecord.push_back({2, userId});
        }
        // enter, change
        else{
            string cond = v[i][0];
            string userId = v[i][1];
            string name = v[i][2];
            if(cond == "Enter"){
                userInfo[userId] = name;
                inOutRecord.push_back({1, userId});
            }
            else if(cond == "Change")
                userInfo[userId] = name;
        }
    }   
    for(int i=0; i<inOutRecord.size();i++){
        int cond = inOutRecord[i].first;
        string userId = inOutRecord[i].second;
        string tmp;
        // enter
        if(cond == 1){
            tmp = userInfo[userId] + "님이 들어왔습니다.";
        }
        // leave
        else{
            tmp = userInfo[userId] + "님이 나갔습니다.";
        }
        answer.push_back(tmp);
    }
}

vector<string> solution(vector<string> record) {
    splitRecord(record);
    solve();
    // debug();
    return answer;
}