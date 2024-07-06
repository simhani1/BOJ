import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N;
    private static Building[] buildings;
    private static final int INF = Integer.MAX_VALUE;

    static class Building {
        int idx;
        int height;
        int visibleCnt;
        Building leftBuilding;
        Building rightBuilding;

        public Building(int idx, int height, int visibleCnt, Building leftBuilding, Building rightBuilding) {
            this.idx = idx;
            this.height = height;
            this.visibleCnt = visibleCnt;
            this.leftBuilding = leftBuilding;
            this.rightBuilding = rightBuilding;
        }

        @Override
        public String toString() {
            return "Building{" +
                "idx=" + idx +
                ", height=" + height +
                ", leftBuilding=" + leftBuilding +
                ", rightBuilding=" + rightBuilding +
                '}';
        }
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        buildings = new Building[N + 1];
        for (int i = 1; i <= N; i++) {
            buildings[i] = new Building(i, Integer.parseInt(st.nextToken()), 0, null, null);
        }
        calcLeft();
        calcRight();
        for (int i = 1; i <= N; i++) {
            Building building = buildings[i];
            if (building.leftBuilding == null && building.rightBuilding == null) {
                sb.append(0).append("\n");
                continue;
            }
            int leftDist = INF, rightDist = INF;
            if (building.leftBuilding != null) {
                leftDist = Math.abs(building.idx - building.leftBuilding.idx);
            }
            if (building.rightBuilding != null) {
                rightDist = Math.abs(building.idx - building.rightBuilding.idx);
            }
            if (leftDist <= rightDist) {
                sb.append(building.visibleCnt)
                    .append(" ")
                    .append(building.leftBuilding.idx)
                    .append("\n");
            } else {
                sb.append(building.visibleCnt)
                    .append(" ")
                    .append(building.rightBuilding.idx)
                    .append("\n");
            }
        }
        System.out.println(sb);
    }

    private static void calcRight() {
        Stack<Building> stack = new Stack<>();
        stack.add(buildings[N]);
        for (int i = N - 1; i >= 1; i--) {
            Building nowBuilding = buildings[i];
            while (!stack.isEmpty() && stack.peek().height <= nowBuilding.height) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                nowBuilding.rightBuilding = stack.peek();
                nowBuilding.visibleCnt += stack.size();
            }
            stack.add(nowBuilding);
        }
    }

    private static void calcLeft() {
        Stack<Building> stack = new Stack<>();
        stack.add(buildings[1]);
        for (int i = 2; i <= N; i++) {
            Building nowBuilding = buildings[i];
            while (!stack.isEmpty() && stack.peek().height <= nowBuilding.height) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                nowBuilding.leftBuilding = stack.peek();
                nowBuilding.visibleCnt += stack.size();
            }
            stack.add(nowBuilding);
        }
    }

}