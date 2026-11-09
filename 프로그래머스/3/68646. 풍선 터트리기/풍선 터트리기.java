/*
a[i] 가 살아남기 위한 조건
a[i] < 왼쪽 최솟값 or a[i] < 오른쪽 최솟값
나보다 큰 풍선을 터트리면 됨

결국 가장 작은 숫자가 생존하게 된다
각 인덱스 기준 좌,우 구간의 최솟값을 알고 있으면 각 자리의 숫자만 남길 수 있는지 알 수 있다
남길 수 있는 조건 = 내 기준 좌,우 구간의 최솟값 중 하나 이상이 나보다 크면 됨
*/

class Solution {
    public int solution(int[] a) {
        int N = a.length;
        int[] left = new int[N];
        int[] right = new int[N];   
        
        left[0] = a[0];
        for (int i = 1; i < N; i++) {
            left[i] = Math.min(left[i - 1], a[i]);
        }
        
        right[N - 1] = a[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            right[i] = Math.min(right[i + 1], a[i]);
        }
        
        int answer = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] <= left[i] || a[i] <= right[i]) answer++;
        }
        return answer;
    }
}