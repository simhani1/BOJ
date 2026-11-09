class Solution {
    public long solution(int n, int[] times) {
        
        long answer = 0, l = 1, r = (long)n * 1_000_000_000;
        while (l <= r) {
            long mid = (l + r) / 2;
            long cnt = check(mid, times);
            if (n <= cnt) {
                answer = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }        
        return answer;
    }
    
    long check(long p, int[] times) {
        long ret = 0;
        for (int i = 0; i < times.length; i++) {
            long time = (long)times[i];
            ret += p / time;
        }
        return ret;
    }
}