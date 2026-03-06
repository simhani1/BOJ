import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int T, N, M;
	static int[][] pos;
	static List<Integer>[] arr;
	static final int MAX = 100_001;

	public static void main(String[] args) throws Exception {
		T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			N = Integer.parseInt(br.readLine());
			init();
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				int x =  Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				arr[x].add(y);
			}
			for (int i = 0; i < MAX; i++) {
				arr[i].sort((o1, o2) -> Integer.compare(o1, o2));
			}
			int nowX, nowY, pk;
			nowX = nowY = pk = 0;
			while (nowX < MAX) {
				if (arr[nowX].isEmpty()) {
					nowX++;
					continue;
				}
				if (arr[nowX].get(arr[nowX].size() - 1) == nowY) {
					for (int i = arr[nowX].size() - 1; i >= 0; i--) {
						nowY = arr[nowX].get(i);
						pk++;
						pos[pk][0] = nowX;
						pos[pk][1] = nowY;
					}
				} else {
					for (int i = 0; i < arr[nowX].size(); i++) {
						nowY = arr[nowX].get(i);
						pk++;
						pos[pk][0] = nowX;
						pos[pk][1] = nowY;
					}
				}
				nowX++;
			}
			st = new StringTokenizer(br.readLine());
			M = Integer.parseInt(st.nextToken());
			for (int i = 0; i < M; i++) {
				int id = Integer.parseInt(st.nextToken());
				sb.append(pos[id][0])
					.append(" ")
					.append(pos[id][1])
					.append("\n");
			}
		}
		System.out.println(sb);
	}

	private static void init() {
		arr = new ArrayList[MAX];
		for (int i = 0; i < MAX; i++) {
			arr[i] = new ArrayList<>();
		}
		pos = new int[MAX][2];
	}
}