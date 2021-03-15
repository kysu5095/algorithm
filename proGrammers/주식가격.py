# 주식가격

def solution(prices):
    answer = [0 for _ in range(len(prices))]
    for i in range(len(prices)):
        t = 0
        for j in range(i+1, len(prices)):
            t += 1
            if prices[i] > prices[j]: break
        answer[i] = t
    return answer