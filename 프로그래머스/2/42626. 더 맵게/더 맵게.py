import heapq

def solution(scoville, K):
    answer = 0
    pq = []
    
    for x in scoville:
        heapq.heappush(pq, x)
    
    while pq[0] < K: 
        if len(pq) < 2:
            return -1
        
        first = heapq.heappop(pq)
        second = heapq.heappop(pq)
        heapq.heappush(pq, first + second * 2)
        
        answer += 1
        
    return answer