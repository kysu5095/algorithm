def solution(dartResult):
    answer = 0
    arr = list()
    for i in range(len(dartResult)):
        if dartResult[i] == '1':
            if dartResult[i+1] == '0': arr.append('10')
            else: arr.append('1')
        elif dartResult[i] == '0':
            if i == 0 or dartResult[i-1] != '1': arr.append('0')
        else: arr.append(dartResult[i])
    idx = 0
    game = [0]*3
    for i in range(len(arr)):
        if   arr[i] == 'S': game[idx-1] = game[idx-1]**1
        elif arr[i] == 'D': game[idx-1] = game[idx-1]**2
        elif arr[i] == 'T': game[idx-1] = game[idx-1]**3
        elif arr[i] == '*': 
            game[idx-1] *= 2
            if idx >= 2: game[idx-2] *= 2
        elif arr[i] == '#': game[idx-1]*=-1
        else:
            game[idx] = int(arr[i])
            idx += 1
    for i in game: answer += i
    return answer