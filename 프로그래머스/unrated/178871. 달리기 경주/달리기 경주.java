import java.util.*;

class Solution {
    
    private Map<String, Integer> ranking = new HashMap<>();
    
    public String[] solution(String[] players, String[] callings) {        
        
        init(players);
        
        for(String nowPlayer : callings){
            int nowPlayerRank = ranking.get(nowPlayer);
            String fasterPlayer = players[nowPlayerRank - 1];
            
            players[nowPlayerRank - 1] = nowPlayer;
            players[nowPlayerRank] = fasterPlayer;
            
            ranking.put(nowPlayer, nowPlayerRank - 1);
            ranking.put(fasterPlayer, nowPlayerRank);
        }
        return players;
    }

    private void init(String[] players){
        for(int i=0;i<players.length;i++){
            ranking.put(players[i], i);
        }
    }
    
}