import sys
input = sys.stdin.readline

if __name__ == '__main__':
    n, m = map(int, input().split())
    arr = [list(input().rstrip('\n')) for _ in range(n)]

    y, x = -1, -1
    v = []
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 'I':
                y, x = i, j
            elif arr[i][j] == 'R':
                v.append([True, i, j])

    command = list(input().rstrip('\n'))
    for i in range(len(command)):
        command[i] = ord(command[i]) - ord('0')

    dy = [0, 1, 1, 1, 0, 0, 0, -1, -1, -1]
    dx = [0, -1, 0, 1, -1, 0, 1, -1, 0, 1]
    for i, d in enumerate(command):
        arr[y][x] = '.'
        y += dy[d]
        x += dx[d]
        if (arr[y][x] == 'R'):
            print("kraj {0}".format(i + 1))
            exit(0)
        arr[y][x] = 'I'

        visited = [[0] * m for _ in range(n)]
        for idx, node in enumerate(v):
            flag = node[0]
            ny = node[1]
            nx = node[2]
            if flag == False: continue
            min_val = float('inf')
            nd = 0
            for j in range(1, 10):
                nny = ny + dy[j]
                nnx = nx + dx[j]
                dis = abs(y - nny) + abs(x - nnx)
                if dis < min_val:
                    min_val = dis;
                    nd = j
            arr[ny][nx] = '.'
            ny += dy[nd]
            nx += dx[nd]
            if arr[ny][nx] == 'I':
                print("kraj {0}".format(i + 1))
                exit(0)
            v[idx][1] = ny
            v[idx][2] = nx
            visited[ny][nx] += 1

        for j, node in enumerate(v):
            flag = node[0]
            if flag == False: continue
            ny = node[1]
            nx = node[2]
            if visited[ny][nx] >= 2: v[j][0] = False
            else: arr[ny][nx] = 'R'

    for i in arr:
        print(''.join(map(str, i)))
