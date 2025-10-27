import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static final int INF = 987654321;
	static int T, K;
	static int[] arr, pSum;
	static int[][] dp;

	public static void main(String[] args) throws Exception {
		T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			K = Integer.parseInt(br.readLine());
			arr = new int[K + 1];
			dp = new int[K + 1][K + 1];
			pSum = new int[K + 1];
			st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= K; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
				pSum[i] = pSum[i - 1] + arr[i];
			}
			for (int diff = 1; diff <= K; diff++) {
				for (int l = 1; l + diff <= K; l++) {
					int r = l + diff;
					dp[l][r] = INF;
					for (int k = l; k < r; k++) {
						dp[l][r] = Math.min(dp[l][r],
							dp[l][k] + dp[k + 1][r] + pSum[r] - pSum[l - 1]);
					}
				}
			}
			sb.append(dp[1][K]).append("\n");
		}
		System.out.println(sb);
	}
}