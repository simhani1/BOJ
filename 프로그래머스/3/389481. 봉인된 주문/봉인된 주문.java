import java.util.*;

class Solution {
    
    long N;
    String[] bans;
    final int exp = 26;

    public String solution(long n, String[] bans) {
        this.N = n;
        this.bans = bans;
        Arrays.sort(bans, (o1, o2) -> {
            if (o1.length() == o2.length()) {
                return o1.compareTo(o2);
            }
            return Integer.compare(o1.length(), o2.length());
        });
        for (String ban : bans) {
            long seq = 0L;
            for (int i = 0; i < ban.length(); i++) {
                char c = ban.charAt(i);
                seq += (c - 'a' + 1) * Math.pow(exp, ban.length() - 1 - i);
            }
            if (seq <= N) {
                N++;
            }
        }
        StringBuilder sb = new StringBuilder();
        while (N > 0L) {
            long mod = N % exp;
            N /= exp;
            // 제일 왼쪽 문자가 z라면 mod = 0
            // 26을 버리기 위해 나눗셈한 값에 1을 빼기
            if (mod == 0) {
                N--;
                mod = 26;
            }
            sb.append((char)('a' + mod - 1)); 
        }
        return sb.reverse().toString();
    }
}