import java.util.*;

class Solution {
    public int solution(int n, int k) {
        StringBuilder sb = new StringBuilder();
        while (n != 0) {
            sb.append(n % k);
            n /= k;
        }
        String changed = sb.reverse().toString();

        String[] arr = changed.split("0+");
        int ret = 0;
        for (String num : arr) {
            if (isPrime(Long.parseLong(num)))
                ret++;
        }
        return ret;
    }
    
    public boolean isPrime(long num) {
        if (num == 1) return false;
        if (num == 2) return true;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
}