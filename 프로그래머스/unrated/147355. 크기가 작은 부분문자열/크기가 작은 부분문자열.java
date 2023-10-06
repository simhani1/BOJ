class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        long pNum = Long.parseLong(p);
        System.out.println(pNum);
        for(int i=0;i<=t.length() - p.length();i++){
            long tNum = Long.parseLong(t.substring(i, i + p.length()));
            if(tNum <= pNum)
                answer++;
        }
        return answer;
    }
}