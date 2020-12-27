#include <stdio.h>
#define MAX 101

int map[MAX][MAX];
int result[MAX][MAX];
int visited[MAX];

void DFS(int start, int limit) {
	// 시작점에서 이동 가능한 모든 정점 탐색
	for (int v = 0; v < limit; v++) {
		// 방문하지 않았고, 이동 가능하면 DFS 시작
		if (!visited[v] && map[start][v]) {
			// 방문 표시는 나중에. 순회가 있을 수 있으므로
			visited[v] = 1;

			// DFS 재귀 호출
			DFS(v, limit);
		}
	}
}

int main(void) {
	int N = 0;

	scanf("%d", &N);

	for (int start = 0; start < N; start++) {
		for (int end = 0; end < N; end++) {
			scanf("%d", &map[start][end]);
		}
	}

	// 맵 탐색 시작
	for (int s = 0; s < N; s++) {
		DFS(s, N);

		for (int v = 0; v < N; v++) {
			result[s][v] = visited[v];
		}

		for (int i = 0; i < N; i++) {
			visited[i] = 0;
		}
	}

	// 결과 출력
	for (int start = 0; start < N; start++) {
		for (int end = 0; end < N; end++) {
			printf("%d ", result[start][end]);
		}
		printf("\n");
	}

	return 0;
}