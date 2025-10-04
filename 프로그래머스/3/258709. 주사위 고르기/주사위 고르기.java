import java.util.*;

class Solution {
    int N, maxWin;
    int[][] dice;
    int[] answer;
    List<Integer> listA, listB;
    
    public int[] solution(int[][] dice) {
        this.dice = dice;
        N = dice.length;
        maxWin = 0;
        listA = new ArrayList<>();
        listB = new ArrayList<>();
        answer = new int[N / 2];
        dfs(0, 0, 0);
        return answer;
    }
    
    public void dfs(int depth, int idx, int bit) {
        if (depth == N / 2) {
            int win = calcWin(bit);
            if (win > maxWin) {
                maxWin = win;
                int ptr = 0;
                for (int i = 0; i < N; i++) {
                    if ((bit & (1 << i)) != 0) {
                        answer[ptr++] = i + 1;
                    }
                }
            }
            return;
        }
        for (int i = idx; i < N; i++) {
            dfs(depth + 1, i + 1, bit | (1 << i));
        }  
    }
    
    public int calcWin(int bit) {
        makeAllList(bit);
        Collections.sort(listA);
        Collections.sort(listB);
        int ret = 0;
        for (int numA : listA) {
            int cnt = -1;
            
            int l = 0, r = listB.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (numA > listB.get(mid)) {
                    l = mid + 1;
                    cnt = mid;
                } else {
                    r = mid - 1;
                }
            }
            ret += (cnt + 1);   
        }
        return ret;
    }
    
    public void makeAllList(int bit) {
        int[][] diceA = new int[N / 2][6];
        int[][] diceB = new int[N / 2][6];
        int idxA = 0, idxB = 0;
        for (int i = 0; i < N; i++) {
            if ((bit & (1 << i)) != 0) {
                diceA[idxA++] = dice[i];
            } else {
                diceB[idxB++] = dice[i];
            }
        }

        listA.clear();
        listB.clear();
        makeList(diceA, listA, 0, 0);
        makeList(diceB, listB, 0, 0);
    }
    
    public void makeList(int[][] dice, List<Integer> list, int depth, int sum) {
        if (depth == N / 2) {
            list.add(sum);
            return;
        }
        for (int i = 0; i < 6; i++) {
            makeList(dice, list, depth + 1, sum + dice[depth][i]);
        }
    }
}