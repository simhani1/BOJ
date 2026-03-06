import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int N, M, K;
	static long[] tree, arr;

	static long init(int node, int nodeL, int nodeR) {
		if (nodeL == nodeR) {
			return tree[node] = arr[nodeL];
		}
		int mid = (nodeL + nodeR) / 2;
		long leftSum = init(node * 2, nodeL, mid);
		long rightSum = init(node * 2 + 1, mid + 1, nodeR);
		return tree[node] = leftSum + rightSum;
	}

	static void update(int node, int nodeL, int nodeR, int idx, long val) {
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
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}

	static long query(int node, int nodeL, int nodeR, int left, int right) {
		if (right < nodeL || nodeR < left) {
			return 0;
		}
		if (left <= nodeL && nodeR <= right) {
			return tree[node];
		}
		int mid = (nodeL + nodeR) / 2;
		long leftSum = query(node * 2, nodeL, mid, left, right);
		long rightSum = query(node * 2 + 1, mid + 1, nodeR, left, right);
		return leftSum + rightSum;
	}

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		arr = new long[N + 1];
		tree = new long[4 * N];
		for (int i = 1; i <= N; i++) {
			arr[i] = Long.parseLong(br.readLine());
		}
		init(1, 1, N);
		for (int i = 1; i <= M + K; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			if (a == 1) {
				long c = Long.parseLong(st.nextToken());
				update(1, 1, N, b, c);
			} else {
				int c = Integer.parseInt(st.nextToken());
				sb.append(query(1, 1, N, b, c)).append("\n");
			}
		}
		System.out.print(sb);
	}
}
