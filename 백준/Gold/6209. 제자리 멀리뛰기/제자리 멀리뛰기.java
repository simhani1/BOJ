import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int D, N, M;
    private static List<Integer> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        D = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            list.add(Integer.parseInt(br.readLine()));
        }
        list.add(D);
        Collections.sort(list);
        System.out.println(parametricSearch());
    }


    private static int parametricSearch() {
        int l = 1, r = D;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (isPossible(mid)) {
                ans = Math.max(ans, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }

    private static boolean isPossible(int target) {
        int now = 0;
        int removeCnt = M;
        for (int i = 0; i < N; i++) {
            int dist = list.get(i) - now;
            if (dist < target) {
                if (removeCnt == 0) {
                    return false;
                }
                removeCnt--;
                continue;
            }
            now = list.get(i);
        }
        return true;
    }
}