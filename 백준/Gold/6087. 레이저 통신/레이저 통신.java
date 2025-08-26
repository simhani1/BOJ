import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, M;
	static int sx, sy;
	static char[][] arr;
	static int[][][] cnt;
	static boolean[][][] visited;
	static int[] dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};
	static final int INF = 987654321;

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		arr = new char[N][M];
		cnt = new int[N][M][4];
		visited = new boolean[N][M][4];
		for (int i = 0; i < N; i++) {
			arr[i] = br.readLine().toCharArray();
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < 4; k++) {
					cnt[i][j][k] = INF;
				}
				if (arr[i][j] == 'C') {
					sx = i;
					sy = j;
				}
			}
		}
		bfs();
	}

	static class Node {
		int x, y, changedCnt, dir;

		public Node(int x, int y, int changedCnt, int dir) {
			this.x = x;
			this.y = y;
			this.changedCnt = changedCnt;
			this.dir = dir;
		}
	}

	private static void bfs() {
		Queue<Node> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.changedCnt, o2.changedCnt));
		pq.offer(new Node(sx, sy, 0, 0));
		pq.offer(new Node(sx, sy, 0, 1));
		pq.offer(new Node(sx, sy, 0, 2));
		pq.offer(new Node(sx, sy, 0, 3));
		for (int i = 0; i < 4; i++) {
			cnt[sx][sy][i] = 0;
			visited[sx][sy][i] = true;
		}
		while (!pq.isEmpty()) {
			Node node = pq.poll();
			int nowX = node.x;
			int nowY = node.y;
			int nowChangedCnt = node.changedCnt;
			int nowDir = node.dir;
			if (!(nowX == sx && nowY == sy) && arr[nowX][nowY] == 'C') {
				int ans = INF;
				for (int i = 0; i < 4; i++) {
					ans = Math.min(ans, cnt[nowX][nowY][i]);
				}
				System.out.println(ans);
				return;
			}
			for (int i = 0; i < 4; i++) {
				int nextX = nowX + dx[i];
				int nextY = nowY + dy[i];
				if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) {
					continue;
				}
				if (arr[nextX][nextY] == '*') {
					continue;
				}
				int nextChangedCnt = cnt[nowX][nowY][nowDir];
				if (nowDir != -1 && nowDir != i) {
					nextChangedCnt++;
				}
				if (!visited[nextX][nextY][i] || cnt[nextX][nextY][i] > nextChangedCnt) {
					visited[nextX][nextY][i] = true;
					cnt[nextX][nextY][i] = nextChangedCnt;
					pq.offer(new Node(nextX, nextY, nextChangedCnt, i));
				}
			}
		}
	}
}
