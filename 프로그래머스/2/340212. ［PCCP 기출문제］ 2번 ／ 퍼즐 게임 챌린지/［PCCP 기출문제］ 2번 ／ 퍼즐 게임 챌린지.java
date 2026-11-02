import java.util.*;

class Solution {
    int[] diffs;
    int[] times;
    long limit;
    
    public int solution(int[] diffs, int[] times, long limit) {
        this.diffs = diffs;
        this.times = times; 
        this. limit = limit;
        
        int l = 1, r = 100_000;
        int answer = Integer.MAX_VALUE;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                answer = Math.min(answer, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return answer;
    }
    
    boolean check(int level) {
        long sum = 0L;
        for (int i = 0; i < diffs.length; i++) {
            if (diffs[i] <= level) {
                sum += times[i];
            } else {
                sum += (diffs[i] - level) * (times[i] + times[i - 1]);
                sum += times[i];
            }
        }
        return sum <= limit;
    }
}