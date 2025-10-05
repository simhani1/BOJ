import java.util.*;

class Solution {
    
    int N, C, G;
    Set<Integer> mine, picked;

    public int solution(int coin, int[] cards) {
        mine = new HashSet<>();
        picked = new HashSet<>();
        N = cards.length;
        G = N + 1;
        C = coin;
        for (int i = 0; i < N / 3; i++) {
            mine.add(cards[i]);
        }
        
        int ret = 1;
        for (int i = N / 3; i < N; i += 2) {
            picked.add(cards[i]);
            picked.add(cards[i + 1]);
            if (checkFirst() || checkSecond() || checkThird())
                ret++; 
            else
                break;
        }
        return ret;
    }
    
    public boolean checkFirst() {
        for (int num : mine) {
            if (mine.contains(G - num)) {
                mine.remove(num);
                mine.remove(G - num);
                return true;
            }
        }
        return false;
    }
    
    public boolean checkSecond() {
        if (C < 1) return false;
        for (int num : mine) {
            if (picked.contains(G - num)) {
                mine.remove(num);
                picked.remove(G - num);
                C--;
                return true;
            }
        }
        return false;
    }
    
    public boolean checkThird() {
        if (C < 2) return false;
        for (int num : picked) {
            if (picked.contains(G - num)) {
                picked.remove(num);
                picked.remove(G - num);
                C -= 2;
                return true;
            }
        }
        return false;
    }        
}