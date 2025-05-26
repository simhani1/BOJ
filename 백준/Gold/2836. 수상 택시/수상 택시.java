import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N, M;
    static List<Taxi> list = new ArrayList<>();

    static class Taxi {
        int start;
        int end;

        public Taxi(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public String toString() {
            return "Taxi{" +
                "start=" + start +
                ", end=" + end +
                '}';
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            if (end < start) {
                list.add(new Taxi(start, end));
            }
        }
        list.sort((o1, o2) -> {
            if (o1.end == o2.end) {
                return Integer.compare(o1.start, o2.start) * -1;
            }
            return Integer.compare(o1.end, o2.end);
        });
        long ans = M;
        if (list.size() == 0) {
            System.out.println(ans);
            return; 
        }
        int prevStart = list.get(0).start;
        int prevEnd = list.get(0).end;
        for (int i = 1; i < list.size(); i++) {
            int curStart = list.get(i).start;
            int curEnd = list.get(i).end;
            if (curEnd <= prevStart) {
                prevStart = Math.max(prevStart, curStart);
            } else {
                ans += Math.abs(prevEnd - prevStart) * 2L;
                prevStart = curStart;
                prevEnd = curEnd;
            }
        }
        ans += Math.abs(prevEnd - prevStart) * 2L;
        System.out.println(ans);
    }
}
