import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	private static final int INF = 987654321;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, M, A, B;
	static int[][] arr;
	static int[][] dp;
	static int[] dx = {0, 1}, dy = {1, 0};
	static List<Node> pos = new ArrayList<>();

	static class Node {
		int x, y;

		public Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		A = Integer.parseInt(st.nextToken());
		B = Integer.parseInt(st.nextToken());
		arr = new int[M][N];
		dp = new int[M][N];
		for (int i = 0; i < A; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			arr[b - 1][a - 1] = 1;
			pos.add(new Node(b - 1, a - 1));
		}
		for (int i = 0; i < B; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			arr[b - 1][a - 1] = -1;
		}
		pos.add(new Node(0, 0));
		pos.add(new Node(M - 1, N - 1));
		pos.sort((o1, o2) -> {
			if (o1.x == o2.x) {
				return Integer.compare(o1.y, o2.y);
			}
			return Integer.compare(o1.x, o2.x);
		});
		int ans = 1;
		for (int i = 1; i < pos.size(); i++) {
			initDp();
			Node from = pos.get(i - 1);
			Node to = pos.get(i);
			ans *= dfs(from.x, from.y, to.x, to.y);
		}
		System.out.println(ans);
	}

	private static void initDp() {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				dp[i][j] = -1;
			}
		}
	}

	private static int dfs(int nowX, int nowY, int toX, int toY) {
		if (!(nowX <= toX && nowY <= toY)) {
			return 0;
		}
		if (nowX == toX && nowY == toY) {
			return 1;
		}
		if (dp[nowX][nowY] != -1) {
			return dp[nowX][nowY];
		}
		int ret = 0;
		for (int i = 0; i < 2; i++) {
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];
			if (!(0 <= nextX && nextX < M && 0 <= nextY && nextY < N)) {
				continue;
			}
			if (arr[nextX][nextY] == -1) {
				continue;
			}
			ret += dfs(nextX, nextY, toX, toY);
		}
		return dp[nowX][nowY] = ret;
	}
}