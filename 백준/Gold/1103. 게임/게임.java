import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, M, ans;
	static int[][] arr;
	static int[][] dp;
	static boolean[][] visited;
	static int[] dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
		dp = new int[N][M];
		visited = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			char[] chars = br.readLine().toCharArray();
			for (int j = 0; j < M; j++) {
				arr[i][j] = chars[j] == 'H' ? -1 : chars[j] - '0';
				dp[i][j] = -1;
			}
		}
		System.out.println(dfs(0, 0));
	}

	private static int dfs(int nowX, int nowY) {
		if (visited[nowX][nowY]) {
			System.out.println(-1);
			System.exit(0);
		}
		if (dp[nowX][nowY] != -1) {
			return dp[nowX][nowY];
		}
		visited[nowX][nowY] = true;
		int ret = 1;
		int dist = arr[nowX][nowY];
		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dx[i] * dist;
			int nextY = nowY + dy[i] * dist;
			if (!(0 <= nextX && nextX < N && 0 <= nextY && nextY < M)) {
				continue;
			}
			if (arr[nextX][nextY] == -1) {
				continue;
			}
			ret = Math.max(ret, dfs(nextX, nextY) + 1);
		}
		visited[nowX][nowY] = false;
		return dp[nowX][nowY] = ret;
	}
}
