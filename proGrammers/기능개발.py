def solution(progresses, speeds):
    answer = []
    for i, node in enumerate(progresses):
        if node >= 100: continue
        day = (100-node)/speeds[i]
        if day != int(day): day += 1
        day = int(day)
        ans = 0
        for j in range(i, len(progresses)):
            progresses[j] += speeds[j]*day
            if progresses[j] >= 100: ans+=1
            else:
                progresses[j] -= speeds[j]*day
                break
        if ans > 0: answer.append(ans)
    return answer