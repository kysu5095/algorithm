#순위 검색

def solution(info, query):
    answer = []
    info = [node.split() for node in info]
    querys = []
    for node in query:
        node = node.split()
        while 'and' in node:
            node.remove('and')
        querys.append(node)

    for q in querys:
        val = 0
        for i in info:
            for idx in range(5):
                if q[idx] == '-': continue
                if idx == 4:
                    if int(i[idx]) >= int(q[idx]): val += 1
                else:
                    if i[idx] != q[idx]: break
        answer.append(val)
    #print(answer)
    return answer