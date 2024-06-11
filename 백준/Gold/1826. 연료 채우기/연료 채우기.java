import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, A, B, L, P;
    private static List<Station> stations;
    private static PriorityQueue<Station> pq;

    static class Station {
        int dist;
        int fuel;

        public Station(int dist, int fuel) {
            this.dist = dist;
            this.fuel = fuel;
        }

        @Override
        public String toString() {
            return "Station{" +
                "dist=" + dist +
                ", fuel=" + fuel +
                '}';
        }
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        stations = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            stations.add(new Station(A, B));
        }
        Collections.sort(stations, (o1, o2) -> Integer.compare(o1.dist, o2.dist));
        st = new StringTokenizer(br.readLine());
        L = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());
        System.out.println(solve());
    }

    private static int solve() {
        int ans = 0;
        int idx = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        while (idx < stations.size()) {
            Station station = stations.get(idx);
            if (P >= station.dist) {
                pq.offer(station.fuel);
                idx++;
            } else {
                if (pq.isEmpty()) {
                    return -1;
                }
                P += pq.poll();
                ans++;
            }
        }
        if (P < L) {
            while (!pq.isEmpty()) {
                P += pq.poll();
                ans++;
                if (P >= L) {
                    return ans;
                }
            }
            return -1;
        }
        return ans;
    }

}