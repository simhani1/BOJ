begin = ""
target = ""
words = []
visited = []
answer = 987654321

def solution(input_begin, input_target, input_words):
    global begin, target, words, visited, answer
    begin = input_begin
    target = input_target
    words = input_words
    visited = [False] * len(input_words)
    
    dfs(begin, 0)
    
    return answer if answer != 987654321 else 0

def dfs(now, depth):
    if now == target:
        global answer
        answer = min(answer, depth)
        return
    
    for i in range(len(words)):
        if not visited[i] and check(now, words[i]):
            visited[i] = True
            dfs(words[i], depth + 1)
            visited[i] = False
    
    

def check(s1, s2):
    cnt = 0
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            cnt += 1
    return cnt == 1
        
        

