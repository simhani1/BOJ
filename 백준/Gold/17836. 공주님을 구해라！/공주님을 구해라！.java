import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, M, T;
	static int[][] arr;
	static boolean[][][] visited;
	static int[] dx = {0,0,-1,1}, dy = {-1, 1, 0, 0};
	static final int INF = Integer.MAX_VALUE;

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
		visited = new boolean[2][N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int ret = bfs(0, 0);
		System.out.println(ret <= T ? ret : "Fail");
	}

	static int bfs(int x, int y) {
		Queue<Node> q = new ArrayDeque<>();
		q.offer(new Node(x, y, 0, false));
		visited[0][x][y] = true;
		while (!q.isEmpty()) {
			Node node = q.poll();
			int nowX = node.x;
			int nowY = node.y;
			int nowT = node.t;
			boolean sword = node.sword;
			if (nowX == N - 1 && nowY == M - 1) {
				return nowT;
			}
			for (int i = 0; i < 4; i++) {
				int nextX = nowX + dx[i];
				int nextY = nowY + dy[i];
				if (!(0 <= nextX && nextX < N && 0 <= nextY && nextY < M)) {
					continue;
				}
				if (sword) {
					if (visited[1][nextX][nextY]) {
						continue;
					}
					visited[1][nextX][nextY] = true;
					q.offer(new Node(nextX, nextY, nowT + 1, sword));
				} else {
					if (visited[0][nextX][nextY]) {
						continue;
					}
					if (arr[nextX][nextY] == 0) {
						visited[0][nextX][nextY] = true;
						q.offer(new Node(nextX, nextY, nowT + 1, sword));
					} else if (arr[nextX][nextY] == 2) {
						visited[0][nextX][nextY] = true;
						visited[1][nextX][nextY] = true;
						q.offer(new Node(nextX, nextY, nowT + 1, !sword));
					}
				}
			}
		}
		return INF;
	}

	static class Node {
		int x;
		int y;
		int t;
		boolean sword;

		public Node(int x, int y, int t, boolean sword) {
			this.x = x;
			this.y = y;
			this.t = t;
			this.sword = sword;
		}
	}
}