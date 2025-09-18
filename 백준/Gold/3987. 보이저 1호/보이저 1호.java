import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	private static final int INF = Integer.MAX_VALUE;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, M, px, py, startDir;
	static char[][] arr;
	static int[] dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
	static char[] dirChar = {'U', 'R', 'D', 'L'};

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new char[N][M];
		for (int i = 0; i < N; i++) {
			arr[i] = br.readLine().toCharArray();
		}
		st = new StringTokenizer(br.readLine());
		px = Integer.parseInt(st.nextToken()) - 1;
		py = Integer.parseInt(st.nextToken()) - 1;
		int ansTime = -1, ansDir = -1;
		for (int dir = 0; dir < 4; dir++) {
			startDir = dir;
			int tmp = solve(px, py, dir);
			if (ansTime < tmp) {
				ansTime = tmp;
				ansDir = dir;
			}
		}
		sb.append(dirChar[ansDir])
			.append("\n")
			.append(ansTime == INF ? "Voyager" : ansTime);
		System.out.println(sb);
	}

	private static int solve(int nowX, int nowY, int dir) {
		int cnt = 1;
		while (true) {
			nowX += dx[dir];
			nowY += dy[dir];
			if (!(0 <= nowX && nowX < N && 0 <= nowY && nowY < M) || arr[nowX][nowY] == 'C') {
				return cnt;
			}
			if (nowX == px && nowY == py && dir == startDir) {
				return INF;
			}
			dir = getNextDir(nowX, nowY, dir);
			cnt++;
		}
	}

	private static int getNextDir(int nowX, int nowY, int prevDir) {
		int nextDir = -1;
		if (arr[nowX][nowY] == '\\') {
			if (prevDir == 0) {
				nextDir = 3;
			} else if (prevDir == 3) {
				nextDir = 0;
			} else if (prevDir == 2) {
				nextDir = 1;
			} else if (prevDir == 1) {
				nextDir = 2;
			}
		} else if (arr[nowX][nowY] == '/') {
			if (prevDir == 0) {
				nextDir = 1;
			} else if (prevDir == 1) {
				nextDir = 0;
			} else if (prevDir == 2) {
				nextDir = 3;
			} else if (prevDir == 3) {
				nextDir = 2;
			}
		} else if (arr[nowX][nowY] == '.') {
			nextDir = prevDir;
		}
		return nextDir;
	}
}