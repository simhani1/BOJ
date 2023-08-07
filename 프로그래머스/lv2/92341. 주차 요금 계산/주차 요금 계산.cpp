#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;
int basicTime, basicFee, unitTime, unitFee;
vector<vector<string>> v;
vector<int> answer;
map<string, int> parkingFee, parkingMinute;
map<string, bool> parked;
map<string, string> parkingTime;
vector<string> car;

void convertFeesToInt(vector<int> fees){
    basicTime = fees[0];
    basicFee = fees[1];
    unitTime = fees[2];
    unitFee = fees[3];
}

void split(vector<string> records){
    for(int i=0;i<records.size();i++){
        vector<string> tmp;
        istringstream ss(records[i]);
        string buffer;
        while(getline(ss, buffer, ' ')){
            tmp.push_back(buffer);
        }
        v.push_back(tmp);
    }
}

void calcTime(string carId, string inTime, string outTime){
    int inH=0, inM=0, outH=0, outM=0;
    inH += (int) (inTime[0] - '0') * 10 + (int) (inTime[1] - '0');
    inM += (int) (inTime[3] - '0') * 10 + (int) (inTime[4] - '0');
    outH += (int) (outTime[0] - '0') * 10 + (int) (outTime[1] - '0');
    outM += (int) (outTime[3] - '0') * 10 + (int) (outTime[4] - '0');
    int pTime = (60 - inM + outM) + (outH - (inH + 1)) * 60;
    parkingMinute[carId] += pTime;
}


void calcMoney(){
    for(auto m = parkingMinute.begin();m != parkingMinute.end(); m++){
        string carid = m->first;
        int pTime = m->second, pFee = 0;
        // 기본 요금
        if(pTime <= basicTime)
            pFee = basicFee;
        // 요금 정산 필요
        else
            pFee = basicFee + ceil((pTime - basicTime)/ (float) unitTime) * unitFee;
        answer.push_back(pFee);
    }
}

void solve(){
    for(int i=0;i<v.size();i++){
        string time = v[i][0];
        string carId = v[i][1];
        string cond = v[i][2];
        car.push_back(carId);
        if(cond == "IN"){
            parked[carId] = true;
            parkingTime[carId] = time;
        }
        else if(cond == "OUT"){
            // 시간 계산
            parked[carId] = false;
            calcTime(carId, parkingTime[carId], time);
        }
    }
    // 출차를 하지 않은 차들에 대한 시간 계산
    for(auto carId : car){
        if(parked[carId]){
            calcTime(carId, parkingTime[carId], "23:59");
            parked[carId] = false;
        }
    }
    // 누적 주차 시간에 대한 요금 정산
    calcMoney();
}

void debug(){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<endl;
        }
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    convertFeesToInt(fees);
    split(records);
    solve();
    // debug();
    return answer;
}