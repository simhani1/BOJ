import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int T, N, ans;
	static int[][] arr, dist;
	static int[] dx = {0, 0, 1, -1};
	static int[] dy = {1, -1, 0, 0};
	static final int INF = Integer.MAX_VALUE;

	public static void main(String[] args) throws IOException {
		T = Integer.parseInt(br.readLine());
		arr = new int[100][100];
		dist = new int[100][100];
		for (int t = 1; t <= T; t++) {
			sb.append("#").append(t).append(" ");
			N = Integer.parseInt(br.readLine());
			for (int i = 0; i < N; i++) {
				String str = br.readLine();
				for (int j = 0; j < N; j++) {
					arr[i][j] = str.charAt(j) - '0';
					dist[i][j] = INF;
				}
			}
			sb.append(bfs()).append("\n");
		}
		System.out.println(sb);
	}

	private static int bfs() {
		Queue<Node> q = new ArrayDeque<>();
		q.offer(new Node(0, 0, arr[0][0]));
		dist[0][0] = arr[0][0];
		while (!q.isEmpty()) {
			Node node = q.poll();
			int nowX = node.x;
			int nowY = node.y;
			int nowCost = node.cost;
			for (int i = 0; i < 4; i++) {
				int nextX = nowX + dx[i];
				int nextY = nowY + dy[i];
				if (!(0 <= nextX && nextX < N && 0 <= nextY && nextY < N)) {
					continue;
				}
				if (dist[nextX][nextY] > nowCost + arr[nextX][nextY]) {
					dist[nextX][nextY] = nowCost + arr[nextX][nextY];
					q.offer(new Node(nextX, nextY, nowCost + arr[nextX][nextY]));
				}
			}
		}
		return dist[N - 1][N - 1];
	}

	static class Node {
		int x;
		int y;
		int cost;

		public Node(int x, int y, int cost) {
			this.x = x;
			this.y = y;
			this.cost = cost;
		}
	}
}