visited = []

def solution(n, computers):
    global visited
    visited = [False] * n
    answer = 0
    
    for computer in range(n):
        if (not visited[computer]):
            dfs(computer, computers)
            answer += 1
        
    return answer

def dfs(now_computer, computers):
    visited[now_computer] = True
    for next_computer in range(len(computers[now_computer])): 
        if computers[now_computer][next_computer] == 1 and not visited[next_computer]:
            dfs(next_computer, computers)