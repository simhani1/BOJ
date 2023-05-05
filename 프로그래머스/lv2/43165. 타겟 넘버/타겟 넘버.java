class Solution {
    
    public int[] arr;
    public int cnt;
    
    public int solution(int[] numbers, int target) {
        cnt = 0;
        arr = numbers.clone();
        dfs(0, 0, target);    
        return cnt;
    }
    
    public void dfs(int idx, int sum, int target) {
        if(idx == arr.length) {
            if(sum == target)
                cnt++;
            return;
        }
        dfs(idx + 1, sum + arr[idx], target);
        dfs(idx + 1, sum - arr[idx], target);
    }
    
}