import java.util.*;

class Solution {
    
    class Work {
        int startTime;
        int endTime;
        
        Work(int startTime, int endTime) {
            this.startTime = startTime;
            this.endTime = endTime;
        }
    }
    
    List<Work> workList = new ArrayList<>();
    
    public int solution(String[] lines) {
        for(int i=0;i<lines.length;i++){
            String[] arr =  lines[i].split(" ");
            int endTime = changeToNum(arr[1]);
            int processingTime = changeProcessingTimeToNum(arr[2]);
            int startTime = endTime - processingTime + 1;
            workList.add(new Work(startTime, endTime));
        }
        int answer = 0;
        for(int i=0;i<workList.size();i++){
            // 종료시간 기준으로 살펴보기
            int l = workList.get(i).endTime;
            int r = l + 999;
            int cnt = 1;
            for(int j=i+1;j<workList.size();j++){
                if(workList.get(j).startTime <= r)
                    cnt++;
            }
            answer = Math.max(answer, cnt);
        }
        return answer;
    }
    
    private int changeToNum(String time) {
        String[] tmp = time.replace(".", ":").split(":");
        int num = 0;
        num += Integer.parseInt(tmp[3]);
        num += (Integer.parseInt(tmp[2]) * 1000);
        num += (Integer.parseInt(tmp[1]) * 60 * 1000);
        num += (Integer.parseInt(tmp[0]) * 60 * 60 * 1000);
        return num;
    }
    
    private int changeProcessingTimeToNum(String time) {
        time = time.replace(".", "").replace("s", "");
        int len = time.length();
        if(len == 4) 
            return Integer.parseInt(time);
        else if(len == 3)
            return Integer.parseInt(time) * 10; 
        else if(len == 2)
            return Integer.parseInt(time) * 100;
        else
            return Integer.parseInt(time) * 1000;
    }
}