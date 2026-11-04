import java.util.*; 

class Job {
    int progress, idx;
    public Job(int progress, int idx) {
        this.progress = progress;
        this.idx = idx;
    }
}

class Solution {
    
    public int[] solution(int[] progresses, int[] speeds) {
        
        Stack<Job> stack = new Stack<>();
        for (int i = progresses.length - 1; i >= 0; i--) {
            stack.add(new Job(progresses[i], i));
        }
        
        int day = 0, cnt = 0;
        List<Integer> list = new ArrayList<>();
        while (!stack.isEmpty()) {
            Job job = stack.pop();
            job.progress += (day * speeds[job.idx]);
            if (job.progress < 100) {
                if (cnt > 0) {
                    list.add(cnt);
                    cnt = 0; 
                }
                day += (100 - job.progress) / speeds[job.idx];
                if ((100 - job.progress) % speeds[job.idx] != 0) {
                    day++;
                }
            }
            cnt++;
        }
        list.add(cnt);
        
        int[] ret = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            ret[i] = list.get(i);
        }
        return ret;
    }
}