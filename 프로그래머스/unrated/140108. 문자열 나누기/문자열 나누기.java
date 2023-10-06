class Solution {
    public int solution(String s) {
        int answer = 0;
        int lIdx = 0;
        int same = 0, diff = 0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(lIdx) == s.charAt(i))
                same++;
            else
                diff++;
            if(same == diff){
                answer++;
                lIdx = i + 1;
                same = diff = 0;
            }
        }
        if(same != diff)
            answer++;
        return answer;
    }
}