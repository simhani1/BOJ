import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class House {

    int X;
    int Y;

    public House(int x, int y) {
        X = x;
        Y = y;
    }
}

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N, K, ans = Integer.MAX_VALUE;
    static List<House> houseList = new ArrayList<>();
    static List<House> cordinate = new ArrayList<>();
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        visited = new boolean[N + 1];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            houseList.add(new House(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        selectSafe(0, 0);
        System.out.println(ans);
    }

    private static void selectSafe(int cnt, int idx) {
        if (cnt == K) {
            ans = Math.min(ans, calcDist());
            return;
        }
        for (int i = idx; i < houseList.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                cordinate.add(houseList.get(i));
                selectSafe(cnt + 1, idx + 1);
                cordinate.remove(houseList.get(i));
                visited[i] = false;
            }
        }
    }

    private static int calcDist() {
        int tmp = 0;
        for (int i = 0; i < houseList.size(); i++) {
            int dist = Integer.MAX_VALUE;
            // 대피소가 아니라면
            if (!visited[i]) {
                for (House h : cordinate) {
                    dist = Math.min(dist, Math.abs(houseList.get(i).X - h.X) + Math.abs(houseList.get(i).Y - h.Y));
                }
            }
            if (dist != Integer.MAX_VALUE) {
                tmp = Math.max(tmp, dist);
            }
        }
        return tmp;
    }
}

