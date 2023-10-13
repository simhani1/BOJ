import java.util.*;

class Solution {

    int answer = 0;
    List<Integer>[] arr;
    int[] type;
    boolean[][][] visited;
    
    public int solution(int[] info, int[][] edges) {
        arr = new ArrayList[info.length];
        for(int i=0;i<info.length;i++){
            arr[i] = new ArrayList<>();
        }
        for(int i=0;i<edges.length;i++){
            arr[edges[i][0]].add(edges[i][1]);
            arr[edges[i][1]].add(edges[i][0]);
        }
        type = info;
        visited = new boolean[info.length][info.length + 1][info.length + 1];
        dfs(0, 0, 0);
        return answer;
    }
    
    private void dfs(int now, int sheep, int wolf){
        if(type[now] == 0)
            sheep++;
        else if(type[now] == 1)
            wolf++;
        answer = Math.max(answer, sheep);
        if(sheep <= wolf)
            return;
        for(int i=0;i<arr[now].size();i++){
            int next = arr[now].get(i);
            int tmp = type[now];
            if(!visited[next][sheep][wolf]){
                visited[next][sheep][wolf] = true;
                type[now] = 2;
                dfs(next, sheep, wolf);
                visited[next][sheep][wolf] = false;
                type[now] = tmp;
            }
        }
    }
}