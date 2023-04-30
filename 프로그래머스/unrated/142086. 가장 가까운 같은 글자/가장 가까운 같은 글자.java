class Solution {
    public int[] solution(String s) {
        
        int[] arr = new int[26];
        int[] answer = new int[s.length()];

        for (int i = 0; i < 26; i++) {
            arr[i] = -1;
        }
        
        for (int i = 0; i < s.length(); i++) {
            int nowChar = s.charAt(i) - 'a';
            if (arr[nowChar] == -1) {
                answer[i] = -1;
            } else {
                answer[i] = i - arr[nowChar];
            }
            arr[nowChar] = i;
        }
        return answer;
    }
}