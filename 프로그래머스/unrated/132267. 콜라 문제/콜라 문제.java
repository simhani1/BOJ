class Solution {
    public int solution(int a, int b, int n) {
        int answer = 0;
        while(n >= a){
            int newCola = (n / a) * b;
            int emptyCola = n % a;
            n = newCola + emptyCola;
            answer += newCola;
        }
        return answer;
    }
}