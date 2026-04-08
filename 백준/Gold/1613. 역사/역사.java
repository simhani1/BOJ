import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int N, K, S;
	static int[][] dist;

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		dist = new int[N + 1][N + 1];
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int front = Integer.parseInt(st.nextToken());
			int back = Integer.parseInt(st.nextToken());
			dist[front][back] = 1;
			dist[back][front] = -1;
		}

		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (i == j) continue;
					if (dist[i][k] == 1 && dist[k][j] == 1) {
						dist[i][j] = 1;
					} else if (dist[i][k] == -1 && dist[k][j] == -1) {
						dist[i][j] = -1;
					}
				}
			}
		}

		S = Integer.parseInt(br.readLine());
		for (int i = 0; i < S; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			sb.append(dist[b][a]).append("\n");
		}

		System.out.println(sb);
	}
}