class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        String answer = "";
        int idx1 = 0, idx2 = 0;
        boolean flag = true;
        for(String str : goal){
            if(idx1 != cards1.length){
                if(str.equals(cards1[idx1])){
                    idx1++;
                    continue;   
                }   
            }
            if(idx2 != cards2.length){
                if(str.equals(cards2[idx2])){
                    idx2++;
                    continue;
                }   
            }
            flag = false;
            break;
        }
        answer = (flag) ? "Yes" : "No";
        return answer;
    }
}