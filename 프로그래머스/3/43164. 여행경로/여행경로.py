tickets = []
visited = []
answer = []
N = 0


def solution(input_tickets):
    global tickets, visited, answer, N
    
    tickets = input_tickets
    N = len(tickets)
    visited = [False] * N
    answer = []
    
    tickets.sort()
    
    dfs("ICN", ["ICN"])

    return answer

def dfs(now, path):
    global answer
    if answer:
        return
    if len(path) == len(tickets) + 1:
        answer = path[:]
        return
    for i in range(N):
        start = tickets[i][0]
        end = tickets[i][1]
        
        if not visited[i] and start == now:
            visited[i] = True
            path.append(end)
            
            dfs(end, path)
            
            visited[i] = False
            path.pop()