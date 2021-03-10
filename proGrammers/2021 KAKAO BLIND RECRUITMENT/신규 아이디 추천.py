# 신규 아이디 추천

def solution(new_id):
    answer = ''
    new_id = new_id.lower()
    for ch in new_id:
        if ch.isalpha() or ch.isdigit() or ch in ['-', '_', '.']:
            answer += ch
    while ".." in answer:
        answer = answer.replace("..", ".")
    if answer[0] == '.':
        answer = answer[1:] if len(answer) > 1 else '.'
    if answer[-1] == '.':
        answer = answer[:-1]
    if len(answer) == 0: answer = 'a'
    if len(answer) > 15:
        answer = answer[:15]
        if answer[-1] == '.':
            answer = answer[:-1]
    if len(answer) <= 2:
        while len(answer) < 3:
            answer += answer[-1]
    return answer