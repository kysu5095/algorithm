from collections import deque
def solution(cacheSize, cities):
    answer = 0
    for i in range(len(cities)): cities[i] = cities[i].lower()
    cache = deque()

    for node in cities:
        if node in cache:
            answer += 1
            cache.remove(node)
            cache.append(node)
        else:
            answer += 5
            if cacheSize == 0: continue
            if len(cache) == cacheSize:
                cache.popleft()
            cache.append(node)
    return answer