import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int T, F;
    private static Map<String, Integer> map = new HashMap<>();
    private static int[] parent;
    private static int[] friends;
    private static final int INF = 200001;

    public static void main(String[] args) throws Exception {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            F = Integer.parseInt(br.readLine());
            init();
            int idx = 1;
            for (int i = 0; i < F; i++) {
                st = new StringTokenizer(br.readLine());
                String a = st.nextToken();
                String b = st.nextToken();
                map.put(a, map.getOrDefault(a, idx++));
                map.put(b, map.getOrDefault(b, idx++));
                union(map.get(a), map.get(b));
                sb.append(friends[
                    Math.min(
                        find(map.get(a)),
                        find(map.get(b))
                    )]).append("\n");
            }
        }
        System.out.println(sb);
    }

    private static void init() {
        map.clear();
        parent = new int[INF];
        friends = new int[INF];
        for (int i = 0; i < INF; i++) {
            parent[i] = i;
            friends[i] = 1;
        }
    }

    private static void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            parent[Math.max(a, b)] = Math.min(a, b);
            friends[Math.min(a, b)] += friends[Math.max(a, b)];
        }
    }

    private static int find(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }

}