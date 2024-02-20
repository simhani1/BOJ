import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M, ans = Integer.MAX_VALUE;
    private static List<Pos> houseList = new ArrayList<>();
    private static List<Pos> chickenList = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                int type = Integer.parseInt(st.nextToken());
                if (type == 1) {
                    houseList.add(new Pos(i, j));
                } else if (type == 2) {
                    chickenList.add(new Pos(i, j));
                }
            }
        }
        solve(0, 0, 0);
        System.out.println(ans);
    }

    private static void solve(int idx, int cnt, int bit) {
        if (cnt == M) {
            ans = Math.min(ans, calcDist(bit));
            return;
        }
        for (int i = idx; i < chickenList.size(); i++) {
            /* 치킨집 고르기 */
            if ((bit & 1 << i) == 0) {
                solve(i + 1, cnt + 1, bit | 1 << i);
            }
        }
    }

    private static int calcDist(int bit) {
        int dist = 0;
        for (Pos house : houseList) {
            int hx = house.x;
            int hy = house.y;
            int tmp = Integer.MAX_VALUE;
            for (int i = 0; i < chickenList.size(); i++) {
                if ((bit & 1 << i) != 0) {
                    Pos chicken = chickenList.get(i);
                    int cx = chicken.x;
                    int cy = chicken.y;
                    tmp = Math.min(tmp, Math.abs(hx - cx) + Math.abs(hy - cy));
                }
            }
            dist += tmp;
        }
        return dist;
    }

    static class Pos {
        int x;
        int y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}