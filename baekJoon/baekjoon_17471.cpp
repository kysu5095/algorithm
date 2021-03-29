// 게리맨더링

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <limits.h>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

int n, res = INT_MAX;
int arr[11], people[11];
bool visited[11], team_a[11], team_b[11];
vector<int> v[11];

bool find() {
	queue<int> q;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		if (team_a[i]) {
			q.push(i);
			visited[i] = true;
			break;
		}
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int& next : v[node]) {
			if (!visited[next] && team_a[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (team_b[i]) {
			q.push(i);
			visited[i] = true;
			break;
		}
	}
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int& next : v[node]) {
			if (!visited[next] && team_b[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (!visited[i])
			return false;
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &people[i]);
	for (int i = 0; i < n; i++) {
		int sz;
		scanf("%d", &sz);
		for(int j = 0; j < sz; j++) {
			int num;
			scanf("%d", &num);
			v[i].push_back(num - 1);
			v[num - 1].push_back(i);
		}
	}
	for (int i = 0; i < n / 2; i++) {
		arr[n - i - 1] = 1;
		do {
			int A = 0, B = 0;
			memset(team_a, false, sizeof(team_a));
			memset(team_b, false, sizeof(team_b));
			for (int j = 0; j < n; j++) {
				if (arr[j]) {
					A += people[j];
					team_a[j] = true;
				}
				else {
					B += people[j];
					team_b[j] = true;
				}
			}
			if (abs(A - B) < res) {
				if (find())
					res = abs(A - B);
			}
		} while (next_permutation(arr, arr + n));
	}
	if (res == INT_MAX) res = -1;
	printf("%d\n", res);
	return 0;
}
