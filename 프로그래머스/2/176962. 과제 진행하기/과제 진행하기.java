import java.util.*;


class Job {
    String name;
    int playtime;
        
    public Job(String name, int playtime) {
        this.name = name;
        this.playtime = playtime;
    }
}

class Solution {
        
    public String[] solution(String[][] plans) {
        Arrays.sort(plans, (a, b) -> {
            return a[1].compareTo(b[1]);
        });
        Arrays.sort(plans, (a, b) -> {
            return a[1].compareTo(b[1]);
        });
        Stack<Job> stack = new Stack<>();
        List<String> ans = new ArrayList<>();
        
        for (int i = 0; i < plans.length - 1; i++) {
            String name = plans[i][0];
            int start = convert(plans[i][1]);
            int playtime = Integer.parseInt(plans[i][2]);
            
            int nextStart = convert(plans[i + 1][1]);
            int remain = nextStart - start;
            
            if (playtime > remain) {
                stack.add(new Job(name, playtime - remain));
                continue;
            }
            
            ans.add(name);
            remain -= playtime;
            
            while (!stack.isEmpty() && remain > 0) {   
                Job job = stack.pop();
                if (job.playtime <= remain) {
                    ans.add(job.name);
                    remain -= job.playtime;
                } else {
                    stack.add(new Job(job.name, job.playtime - remain));
                    break;
                }       
            }
        }
        
        ans.add(plans[plans.length - 1][0]);
        while (!stack.isEmpty()) {
            ans.add(stack.pop().name);
        }
        
        return ans.toArray(new String[0]);
    }
    
    int convert(String playtime) {
        String[] hhmm = playtime.split(":");
        int hour = Integer.parseInt(hhmm[0]);
        int minute = Integer.parseInt(hhmm[1]);
        return hour * 60 + minute;
    }
}