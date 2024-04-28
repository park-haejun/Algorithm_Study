from collections import deque
import sys

input = sys.stdin.readline

n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
temp_graph = [[0] * m for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

queue = deque()
result = 0
def bfs():
    while queue:
        x, y = queue.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            
            if 0 <= nx < n and 0 <= ny < m and temp_graph[nx][ny] == 0:
                queue.append((nx, ny))
                temp_graph[nx][ny] = 2

def makewall(cnt):
    if cnt == 3:
        for i in range(n):
            for j in range(m):
                temp_graph[i][j] = graph[i][j]
                if temp_graph[i][j] == 2:
                    queue.append((i, j))
        bfs()

        area = 0
        global result
        
        for i in range(n):
            area += temp_graph[i].count(0)
        
        result = max(result, area)
        return
            
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                graph[i][j] = 1
                makewall(cnt+1)
                graph[i][j] = 0
            

makewall(0)
print(result)
