import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M, idx = 1;
    private static int[] indegree;
    private static double[] blood;
    private static List<Integer>[] arr;
    private static Map<String, Integer> m = new HashMap<>();

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        indegree = new int[300];
        arr = new ArrayList[300];
        blood = new double[300];
        for (int i = 0; i < 300; i++) {
            arr[i] = new ArrayList<>();
        }
        String start = br.readLine();
        m.put(start, idx++);
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String child = st.nextToken();
            String parent1 = st.nextToken();
            String parent2 = st.nextToken();
            if (!m.containsKey(parent1)) {
                m.put(parent1, idx++);
            }
            if (!m.containsKey(parent2)) {
                m.put(parent2, idx++);
            }
            if (!m.containsKey(child)) {
                m.put(child, idx++);
            }
            indegree[m.get(child)] += 2;
            arr[m.get(parent1)].add(m.get(child));
            arr[m.get(parent2)].add(m.get(child));
        }
        solve(start);
        String name = "";
        double tmp = 0.0;
        for (int i = 0; i < M; i++) {
            String target = br.readLine();
            if (!m.containsKey(target)) {
                continue;
            }
            int idx = m.get(target);
            if (blood[idx] > tmp) {
                tmp = blood[idx];
                name = target;
            }
        }
        System.out.println(name);
    }

    private static void solve(String start) {
        int startIdx = m.get(start);
        blood[startIdx] = 1.0;
        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 1; i <= idx; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }
        while (!q.isEmpty()) {
            int now = q.poll();
            for (int next : arr[now]) {
                indegree[next]--;
                blood[next] += (blood[now] / 2.0);
                if (indegree[next] == 0) {
                    q.offer(next);
                }
            }
        }
    }
}