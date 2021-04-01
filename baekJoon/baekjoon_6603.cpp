// 로또

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
int arr[13];
bool visited[13];

int main() {
	while (true) {
		scanf(" %d", &n);
		if (!n) break;
		for (int i = 0; i < n; i++) scanf(" %d", &arr[i]);
		memset(visited, true, sizeof(visited));
		for (int i = 0; i < 6; i++) visited[i] = false;
		do {
			for (int i = 0; i < n; i++)
				if (!visited[i]) printf("%d ", arr[i]);
			printf("\n");
		} while (next_permutation(visited, visited + n));
		printf("\n");
	}
	return 0;
}