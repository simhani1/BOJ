class Solution {
    public String solution(String play_time, String adv_time, String[] logs) {
        int play = toSecond(play_time);
        int adv = toSecond(adv_time);
        int[] arr = new int[play + 2];
        for (String log : logs) {
            String[] time = log.split("-");
            int start = toSecond(time[0]);
            int end = toSecond(time[1]);
            arr[start]++;
            arr[end]--;
        }
        for (int i = 1; i <= play; i++) {
            arr[i] += arr[i - 1];
        }
        
        long sum = 0;
        for (int i = 0; i < adv; i++) {
            sum += arr[i];
        }
        
        long max = sum;
        int ret = 0;
        for (int i = 1; i + adv <= play; i++) {
            sum -= arr[i - 1];
            sum += arr[i + adv - 1];            
            if (sum > max) {
                max = sum;
                ret = i;
            }
        }
        return toTime(ret);
    }
    
    String toTime(int second) {
        int h = second / 3600;
        int m = (second % 3600) / 60;
        int s = second % 60;
        return String.format("%02d:%02d:%02d", h, m, s);
    }
    
    int toSecond(String time) {
        String[] arr = time.split(":");
        return
            Integer.parseInt(arr[0]) * 3600 +
            Integer.parseInt(arr[1]) * 60 + 
            Integer.parseInt(arr[2]);
    }
}