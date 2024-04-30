import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, sum, cnt;
    private static int[] ans, sameColor, sameColorAndSize;
    private static List<Ball> ballList;

    static class Ball {
        int idx;
        int color;
        int size;

        public Ball(int idx, int color, int size) {
            this.color = color;
            this.idx = idx;
            this.size = size;
        }

        @Override
        public String toString() {
            return "Ball{" +
                    "color=" + color +
                    ", idx=" + idx +
                    ", size=" + size +
                    '}';
        }
    }

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        ballList = new ArrayList<>();
        ballList.add(new Ball(0, 0, 0));
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            int color = Integer.parseInt(st.nextToken());
            int size = Integer.parseInt(st.nextToken());
            ballList.add(new Ball(i, color, size));
        }
        Collections.sort(ballList, (o1, o2) -> {
            if (o1.size == o2.size) {
                return Integer.compare(o1.color, o2.color);
            }
            return Integer.compare(o1.size, o2.size);
        });
        Ball prevBall = ballList.get(0);
        ans = new int[N + 1];
        sameColor = new int[N + 1];
        sameColorAndSize = new int[N + 1];
        sum = cnt = 0;
        for (int i = 1; i <= N; i++) {
            Ball nowBall = ballList.get(i);
            /* 색이 같은 공의 무게 합을 저장 */
            sameColor[prevBall.color] += prevBall.size;
            /* 색 & 크기가 모두 같은 공의 무게 합을 저장 */
            if (prevBall.color == nowBall.color && prevBall.size == nowBall.size) {
                sameColorAndSize[nowBall.color] += prevBall.size;
            }
            if (prevBall.size < nowBall.size) {
                sum += prevBall.size * cnt;
                cnt = 0;
                sameColorAndSize = new int[N + 1];
            }
            ans[nowBall.idx] = sum - sameColor[nowBall.color] + sameColorAndSize[nowBall.color];
            prevBall = nowBall;
            cnt++;
        }
        for (int i = 1; i <= N; i++) {
            sb.append(ans[i]).append("\n");
        }
        System.out.println(sb);
    }

}