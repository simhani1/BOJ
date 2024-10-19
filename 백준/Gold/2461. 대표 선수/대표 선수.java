import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M;
    private static int[][] arr;
    private static int[] idx;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N][M];
        idx = new int[N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < N; i++) {
            Arrays.sort(arr[i]);
        }
        int ans = Integer.MAX_VALUE;
        while (true) {
            int max = 0;
            int min = Integer.MAX_VALUE;
            int minIdx = 0;  // 최솟값의 i 인덱스
            for (int i = 0; i < N; i++) {
                if (min > arr[i][idx[i]]) {
                    min = arr[i][idx[i]];
                    minIdx = i;
                }
                max = Math.max(max, arr[i][idx[i]]);
            }
            ans = Math.min(ans, max - min);
            /* 최솟값의 j 인덱스 증가 */
            idx[minIdx]++; 
            if (idx[minIdx] == M) {
                break;
            }
        }
        System.out.println(ans);
    }

}