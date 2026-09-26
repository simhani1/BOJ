class Solution {
    public int solution(int[] arrayA, int[] arrayB) {
        int gcdA = getGcd(arrayA);
        int gcdB = getGcd(arrayB);

        int ansA = divideNone(gcdA, arrayB) ? gcdA : 0;
        int ansB = divideNone(gcdB, arrayA) ? gcdB : 0;
        return Math.max(ansA, ansB);
    }
    
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    int getGcd(int[] arr) {
        int ret = arr[0];
        for (int i = 1; i < arr.length; i++) {
            ret = gcd(ret, arr[i]);
        }
        return ret;
    }
    
    boolean divideNone(int gcd, int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % gcd == 0) return false;
        }
        return true;
    }
}