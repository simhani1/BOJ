import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static HashMap<Integer, Integer> m = new HashMap<>();
    static int ansTime = Integer.MAX_VALUE;
    static int cnt = 0;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        solve(N, K);
        System.out.println(ansTime);
        System.out.println(cnt);
    }

    private static void solve(int N, int K) {
        Queue<Integer> q = new LinkedList<>();
        int[] time = new int[100001];
        int[] dx = {1, -1, 2};
        q.add(N);
        while (!q.isEmpty()) {
            int now = q.poll();
            if (time[now] > ansTime)
                continue;
            if (now == K) {
                ansTime = time[now];
                cnt++;
                continue;
            }
            for (int i = 0; i < 3; i++) {
                int next;
                if (i == 2)
                    next = now * dx[i];
                else
                    next = now + dx[i];
                if (0 <= next && next <= 100000) {
                    if (time[next] == 0 || time[next] >= time[now] + 1) {
                        q.add(next);
                        time[next] = time[now] + 1;
                    }
                }
            }
        }
    }
}

