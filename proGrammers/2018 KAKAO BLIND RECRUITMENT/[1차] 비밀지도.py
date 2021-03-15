def solution(n, arr1, arr2):
    answer = []
    tmp1 = [[0 for _ in range(n)] for _ in range(n)]
    tmp2 = [[0 for _ in range(n)] for _ in range(n)]
    for idx, node in enumerate(arr1):
        for i in range(n-1,-1,-1):
            tmp1[idx][i] = node % 2
            node = node // 2
    for idx, node in enumerate(arr2):
        for i in range(n-1,-1,-1):
            tmp2[idx][i] = node % 2
            node = node // 2
    for i in range(n):
        string = ""
        for j in range(n):
            if tmp1[i][j] == 1 or tmp2[i][j] == 1: string += "#"
            else: string += " "
        answer.append(string)
    return answer