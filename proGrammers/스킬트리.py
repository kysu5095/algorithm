# 스킬트리

def solution(skill, skill_trees):
    answer = 0
    alpha = {'A':0,'B':0,'C':0,'D':0,'E':0,'F':0,'G':0,'H':0,'I':0,'J':0,'K':0,'L':0,'M':0,'N':0,'O':0,'P':0,'Q':0,'R':0,'S':0,'T':0,'U':0,'V':0,'W':0,'X':0,'Y':0,'Z':0,}
    idx = 1
    for i in skill:
        alpha[i] = idx
        idx += 1
    for i in skill_trees:
        cnt = 1
        flag = True
        for idx in i:
            if alpha[idx] > cnt:
                flag = False
                break
            if alpha[idx] == cnt:
                cnt += 1
        if flag: answer += 1
    return answer