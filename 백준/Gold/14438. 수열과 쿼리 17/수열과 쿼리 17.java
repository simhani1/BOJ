import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int N, M;
	static int[] arr, tree;
	static final int INF = Integer.MAX_VALUE;

	static int init(int node, int nodeL, int nodeR) {
		if (nodeL == nodeR) {
			return tree[node] = arr[nodeL];
		}
		int mid = (nodeL + nodeR) / 2;
		int leftMin = init(node * 2, nodeL, mid);
		int rightMin = init(node * 2 + 1, mid + 1, nodeR);
		return tree[node] = Math.min(leftMin, rightMin);
	}

	static void update(int node, int nodeL, int nodeR, int idx, int val) {
		if (idx < nodeL || nodeR < idx) {
			return;
		}
		if (nodeL == nodeR) {
			tree[node] = arr[idx] = val;
			return;
		}
		int mid = (nodeL + nodeR) / 2;
		update(node * 2, nodeL, mid, idx, val);
		update(node * 2 + 1, mid + 1, nodeR, idx, val);
		tree[node] = Math.min(tree[node * 2], tree[node * 2 + 1]);
	}

	static int query(int node, int nodeL, int nodeR, int left, int right) {
		if (right < nodeL || nodeR < left) {
			return INF;
		}
		if (left <= nodeL && nodeR <= right) {
			return tree[node];
		}
		int mid = (nodeL + nodeR) / 2;
		int leftMin = query(node * 2, nodeL, mid, left, right);
		int rightMin = query(node * 2 + 1, mid + 1, nodeR, left, right);
		return Math.min(leftMin, rightMin);
	}

	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		arr = new int[N + 1];
		tree = new int[4 * N];
		for (int i = 0; i < 4 * N; i++) {
			tree[i] = INF;
		}
		for (int i = 1; i <= N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		init(1, 1, N);
		M = Integer.parseInt(br.readLine());
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			if (a == 1) {
				update(1, 1, N, b, c);
			} else {
				sb.append(query(1, 1, N, b, c)).append("\n");
			}
		}
		System.out.println(sb);
	}
}
