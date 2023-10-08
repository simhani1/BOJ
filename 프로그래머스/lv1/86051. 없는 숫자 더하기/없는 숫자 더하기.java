class Solution {
    public int solution(int[] numbers) {
        int answer = 0;
        boolean[] visited = new boolean[10];
        for(int number : numbers){
            visited[number] = true;
        }
        for(int i=1;i<10;i++){
            if(!visited[i])
                answer += i;
        }
        return answer;
    }
}