# 메뉴 리뉴얼

from itertools import combinations

def solution(orders, course):
    answer = []
    orders = [sorted(i) for i in orders]
    for c in course:
        d = dict()
        for order in orders:
            if len(order) < c: continue
            comb = combinations(order, c)
            for node in comb:
                food = ''.join(node)
                if food not in d: d[food] = 1
                else: d[food] += 1
        d_list = sorted(d.items(), key=lambda x: x[1], reverse=True)
        for key, value in d_list:
            if value < 2: break
            if value == d_list[0][1]: answer.append(key)
            else: break
    return sorted(answer)