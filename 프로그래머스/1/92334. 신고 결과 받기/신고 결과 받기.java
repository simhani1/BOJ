import java.util.*;

class Solution {
    
    public int[] solution(String[] id_list, String[] report, int k) {
        
        int N = id_list.length;
        boolean[][] arr = new boolean[N][N];
        int[] reportedCnt = new int[N];
        List<Integer> ans = new ArrayList<>();
        HashMap<String, Integer> m = new HashMap<>();
        
        // 아이디 - 번호 맵핑
        for(int i=0;i<N;i++){
            m.put(id_list[i], i);
        }
        
        // 2차원 배열로 이용자 - 신고자 맵핑
        for(String r : report){
            String[] info = r.split(" ");
            String userId = info[0], reportedId = info[1];
            // 중복 신고한 경우
            if(arr[m.get(userId)][m.get(reportedId)])
                continue;
            arr[m.get(userId)][m.get(reportedId)] = true;
            reportedCnt[m.get(reportedId)]++;  // 누적 신고 횟수 계산
        }
        
        // 메일 발송 대상 추가
        for(int i=0;i<N;i++){
            int cnt = 0;
            for(int j=0;j<N;j++){
                if(!arr[i][j])  // 신고하지 않은 유저
                    continue;
                if(reportedCnt[j] < k)  // 신고횟수 k번 미만인 경우
                    continue;
                cnt++;
            }
            ans.add(cnt);
        }
        return ans.stream().mapToInt(i->i).toArray();
    }
}