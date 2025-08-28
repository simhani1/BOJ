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
	static int N, H, D;
	static char[][] arr;
	static int[][] dist;
	static int[] dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};
	static final int INF = 987654321;

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		arr = new char[N][N];
		dist = new int[N][N];
		int sx = 0, sy = 0;
		for (int i = 0; i < N; i++) {
			arr[i] = br.readLine().toCharArray();
			for (int j = 0; j < N; j++) {
				// dist[i][j] = INF;
				if (arr[i][j] == 'S') {
					sx = i;
					sy = j;
				}
			}
		}
		int ret = bfs(sx, sy);
		System.out.println(ret == INF ? -1 : ret);
	}

	static class Node {
		int x, y, h, d, cnt;

		public Node(int x, int y, int h, int d, int cnt) {
			this.x = x;
			this.y = y;
			this.h = h;
			this.d = d;
			this.cnt = cnt;
		}
	}

	private static int bfs(int sx, int sy) {
		Queue<Node> q = new ArrayDeque<>();
		q.offer(new Node(sx, sy, H, 0, 0));
		dist[sx][sy] = 0;
		int ret = INF;
		while (!q.isEmpty()) {
			Node node = q.poll();
			int nowX = node.x;
			int nowY = node.y;
			int nowH = node.h;
			int nowD = node.d;
			int nowCnt = node.cnt;
			if (arr[nowX][nowY] == 'E') {
				ret = Math.min(ret, nowCnt);
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nextX = nowX + dx[i];
				int nextY = nowY + dy[i];
				int nextH = nowH;
				int nextD = nowD;
				if (!(0 <= nextX && nextX < N && 0 <= nextY && nextY < N)) continue;
				if (arr[nextX][nextY] == '.') {
					if (nextD == 0) {
						nextH--;
					} else {
						nextD--;
					}
				} else if (arr[nextX][nextY] == 'U') {
					nextD = D;
					if (nextD == 0) {
						nextH--;
					} else {
						nextD--;
					}
				}
				if (nextH > 0 && dist[nextX][nextY] < nextH + nextD) {
					dist[nextX][nextY] = nextH + nextD;
					q.offer(new Node(nextX, nextY, nextH, nextD, nowCnt + 1));
				}
			}
		}
		return ret;
	}
}
