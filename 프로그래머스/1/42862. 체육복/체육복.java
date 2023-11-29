import java.util.*;

class Solution {
    
    boolean[] check = new boolean[31];
    boolean[] isReserve = new boolean[31];
    boolean[] possible = new boolean[31];
    
    
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        for(int i=1;i<=n;i++){
            possible[i] = true;  // 초기화
        }
        for(int reserveNum : reserve){
            isReserve[reserveNum] = true;
            check[reserveNum] = true;  // 빌려줄 수 있는지 여부
        }
        for(int lostNum : lost){
            if(check[lostNum])
                check[lostNum] = false;  // 여벌옷을 도난당한 경우 빌려줄 수 없음
            else
                possible[lostNum] = false;  // 그 외 나머지 학생들은 수업 못들음
        }
        Arrays.sort(lost);
        Arrays.sort(reserve);
        for(int lostNum : lost){
            if(isReserve[lostNum])  // 여벌옷을 도난당한 학생 번호가 lost에 포함되어 있으므로 걸러줘야 한다.
                continue;
            if(check[lostNum - 1]){  // 앞 학생이 빌려줄 수 있다면
                possible[lostNum] = true;  // 수업 참여 가능
                check[lostNum - 1] = false;  // 앞 학생은 빌려주기 불가능
            }
            else if(check[lostNum + 1]){  // 뒤 학생이 빌려줄 수 있다면
                possible[lostNum] = true;  // 수업 참여 가능
                check[lostNum + 1] = false;  // 뒤 학생은 빌려주기 불가능
            }
        }
        for(int i=1;i<=n;i++){
            if(possible[i])  // 참여가 가능한 학생 수 구하기
                answer++;
        }
        return answer;
    }
}