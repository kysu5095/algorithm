def solution(number, k):
    arr = list()
    for i, node in enumerate(number):
        while arr and arr[-1] < node and k > 0:
            arr.pop()
            k-=1
        if k == 0:
            arr += number[i:]
            break
        arr.append(node)
    if k > 0: arr = arr[:-k]
    return ''.join(arr)