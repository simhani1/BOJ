class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 1;
        int l = section[0];
        int r = l + m - 1;
        for(int i : section){
            if(l <= i && i <= r)
                continue;
            else{
                System.out.println(i);
                l = i;
                r = l + m - 1;
                answer++;
            }
        }
        return answer;
    }
}