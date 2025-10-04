import java.util.*;

class Solution {
    Map<String, Integer> map;
    int[][] arr;  // x가 y에게 받은 선물의 개수
    int[] plusGift;
    int[][] record;
    
    public int solution(String[] friends, String[] gifts) {
        int pk = 0;
        map = new HashMap<>();
        for (String friend : friends) {
            map.put(friend, ++pk);
        }
        
        arr = new int[pk + 1][pk + 1];
        record = new int[pk + 1][2];
        for (int i = 0; i < gifts.length; i++) {
            String[] gift = gifts[i].split(" ");
            int A = map.get(gift[0]), B = map.get(gift[1]);
            arr[A][B]++;
            record[A][0]++;
            record[B][1]++;
        }
        
        plusGift = new int[pk + 1];
        for (int i = 1; i <= pk; i++) {
            for (int j = i + 1; j <= pk; j++) {
                int sumA = arr[i][j];  // a가 준 선물
                int sumB = arr[j][i];  // b가 준 선물
                if (sumA > sumB) plusGift[i]++;
                else if (sumA < sumB) plusGift[j]++;
                else {
                    int pntA = record[i][0] - record[i][1];
                    int pntB = record[j][0] - record[j][1];
                    if (pntA > pntB) plusGift[i]++;
                    else if (pntA < pntB) plusGift[j]++;
                }
            }
        }
    
        int ret = 0;
        for (int i = 1; i <= pk; i++) {
            ret = Math.max(ret, plusGift[i]);
        }
        return ret;
    }
}