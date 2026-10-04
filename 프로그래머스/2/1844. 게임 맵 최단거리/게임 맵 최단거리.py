from collections import deque

maps = []
visited = []
answer = 0
N = M = 0

def solution(input_maps):
    global maps, visited, N, M, answer
    maps = input_maps
    N = len(maps)
    M = len(maps[0])
    visited = [[False] * M for _ in range(N)]
    answer = float('inf')
    
    
    return bfs()

def bfs():
    q = deque()
    q.append((0, 0, 1))
    visited[0][0] = True
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]
    while q:
        x, y, dist = q.popleft();
        
        if x == N - 1 and y == M - 1:
            return dist
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if not (0 <= nx and nx < N and 0 <= ny and ny < M):
                continue
            if visited[nx][ny] or maps[nx][ny] == 0:
                continue
                
            visited[nx][ny] = True
            q.append((nx, ny, dist + 1))
                
    return -1
        
        