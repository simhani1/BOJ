import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, ans = 0;
    private static int[][] action = new int[51][10];
    private static int[] sequence = new int[10];

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= 9; j++) {
                action[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        /* 타순 정하기 - 순열 - 8! */
        sequence[4] = 1;
        calc(1, 0);
        System.out.println(ans);
    }

    /**
     * 선수들의 타순을 정함(1번 선수 제외)
     * @param idx 현재 정하고 있는 타순
     */
    private static void calc(int idx, int checked) {
        if (idx == 10) {
            /* 타순이 모두 정해진 경우 */
            play();
            return;
        }
        /* 선수 등번호 */
        for (int i = 2; i <= 9; i++) {
            if ((checked & 1 << i) == 0) {
                sequence[idx] = i;
                calc(idx + 1 == 4 ? idx + 2 : idx + 1, checked | 1 << i);
            }
        }
    }

    private static void play() {
        int score = 0;
        int lastPlayerIdx = 1;
        /* 야구 게임 진행 */
        for (int 이닝 = 1; 이닝 <= N; 이닝++) {
            /* 진루 상태 */
            boolean[] base = new boolean[4];
            int outCnt = 0;
            int[] actionOfPlayers = action[이닝];
            /* 3아웃 전까지 플레이 */
            while (outCnt < 3) {
                /* 타석 입장 */
                int player = sequence[lastPlayerIdx];
                base[0] = true;
                /* 다음 타자 인덱스 */
                lastPlayerIdx++;
                if (lastPlayerIdx == 10) {
                    lastPlayerIdx = 1;
                }
                /* 플레이 */
                switch (actionOfPlayers[player]) {
                    case 0:
                        /* 아웃 */
                        outCnt++;
                        break;
                    case 1:
                        /* 안타 */
                        score += 안타(base);
                        break;
                    case 2:
                        /* 2루타 */
                        score += 이루타(base);
                        break;
                    case 3:
                        /* 3루타 */
                        score += 삼루타(base);
                        break;
                    case 4:
                        /* 홈런 */
                        score += 홈런(base);
                        break;
                }
            }
        }
        ans = Math.max(ans, score);
    }

    private static int 홈런(boolean[] base) {
        int plusPoint = checkBase(base, 3) + checkBase(base, 2) + checkBase(base, 1) + checkBase(base, 0);
        return plusPoint;
    }

    private static int 삼루타(boolean[] base) {
        int plusPoint = checkBase(base, 3) + checkBase(base, 2) + checkBase(base, 1);
        base[3] = base[0];
        base[0] = false;
        return plusPoint;
    }

    private static int 이루타(boolean[] base) {
        int plusPoint = checkBase(base, 3) + checkBase(base, 2);
        base[3] = base[1];
        base[1] = false;
        base[2] = base[0];
        return plusPoint;
    }

    private static int 안타(boolean[] base) {
        int plusPoint = checkBase(base, 3);
        base[3] = base[2];
        base[2] = base[1];
        base[1] = base[0];
        return plusPoint;
    }

    private static int checkBase(boolean[] base, int target) {
        if (base[target]) {
            base[target] = false;
            return 1;
        }
        return 0;
    }
}