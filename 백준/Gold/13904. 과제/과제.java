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
    private static int N, D, W;
    private static List<Work> works = new ArrayList<>();
    private static boolean[] visited;

    static class Work {
        int day;
        int score;

        public Work(int day, int score) {
            this.day = day;
            this.score = score;
        }

        @Override
        public String toString() {
            return "Work{" +
                "day=" + day +
                ", score=" + score +
                '}';
        }
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        int idx = 0;
        visited = new boolean[N + 1];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            D = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());
            works.add(new Work(D, W));
            idx = Math.max(idx, D);
        }
        Collections.sort(works, (o1, o2) -> Integer.compare(o1.score, o2.score) * -1);
        int ans = 0;
        for (int i = idx; i > 0; i--) {
            int maxScore = 0;
            for (int j = 0; j < works.size(); j++) {
                if (visited[j]) {
                    continue;
                }
                Work work = works.get(j);
                /* 오늘 기준 마감되지 않은 작업 중 최대 점수 */
                if (i <= work.day) {
                    maxScore = Math.max(maxScore, work.score);
                    visited[j] = true;
                    break;
                }
            }
            ans += maxScore;
        }
        System.out.println(ans);
    }

}