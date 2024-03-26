import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int T, N;

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            N = Integer.parseInt(br.readLine());
            TreeSet<Integer> set = new TreeSet<>();
            Map<Integer, Integer> m = new HashMap();
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                String op = st.nextToken();
                int num = Integer.parseInt(st.nextToken());
                if (op.equals("I")) {
                    m.put(num, m.getOrDefault(num, 0) + 1);
                    set.add(num);
                } else {
                    if (num == 1) {
                        if (!set.isEmpty()) {
                            deleteNum(set, m, set.last());
                        }
                    } else {
                        if (!set.isEmpty()) {
                            deleteNum(set, m, set.first());
                        }
                    }
                }
            }
            if (set.isEmpty()) {
                sb.append("EMPTY\n");
            } else {
                sb.append(set.last()).append(" ").append(set.first()).append("\n");
            }
        }
        System.out.println(sb.toString());
    }

    private static void deleteNum(TreeSet<Integer> set, Map<Integer, Integer> m, int target) {
        if (m.get(target) == 0) {
            set.remove(target);
            m.remove(target);
        } else {
            m.put(target, m.get(target) - 1);
            if (m.get(target) == 0) {
                set.remove(target);
            }
        }
    }
}