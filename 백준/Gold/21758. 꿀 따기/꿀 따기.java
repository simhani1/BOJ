import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int[] arr = new int[N + 10];
        int[] pSum = new int[N + 10];
        String[] str = br.readLine().split(" ");
        for (int i = 1; i <= str.length; i++) {
            arr[i] = Integer.parseInt(str[i-1]);
            pSum[i] = pSum[i - 1] + arr[i];
        }
        System.out.println(solve(N, arr, pSum));
    }

    private static int solve(int N, int[] arr, int[] pSum) {
        // 왼쪽 벌, 오른쪽 벌집
        int left = 0;
        for (int i = 2; i <= N; i++) {
            left = Math.max(left, pSum[N] - pSum[i] + pSum[N] - arr[1] - arr[i]);
        }
        // 오른쪽 벌, 왼쪽 벌집
        int right = 0;
        for (int i = N - 1; i >= 2; i--) {
            right = Math.max(right, pSum[N - 1] + pSum[i - 1] - arr[i]);
        }
        // 왼쪽 벌, 벌집 중간, 오른쪽 벌
        int mid = 0;
        for (int i = 2; i <= N - 1; i++) {
            mid = Math.max(mid, pSum[i] - pSum[1] + pSum[N] - pSum[i - 1] - arr[N]);
        }
        return Math.max(mid, Math.max(left, right));
    }
}

