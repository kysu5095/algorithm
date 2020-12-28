// 하나로

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
double E;
int parent[1001];
int X[1001], Y[1001];
priority_queue<pair<double, pair<int, int>>> pq;

int find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]);
}

bool is_parent(int y, int x) {
	y = find(y);
	x = find(x);
	if (y == x) return false;
	if (y < x) parent[x] = y;
	else parent[y] = x;
	return true;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int test_case, y, x;
	double pay, cost, res;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf(" %d", &X[i]);
		for (int i = 0; i < n; i++)
			scanf(" %d", &Y[i]);
		scanf(" %lf", &E);
		for (int i = 1; i <= n; i++)
			parent[i] = i;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				pay = (pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2));
				pq.push(make_pair(-pay, make_pair(i, j)));
			}
		}
		res = 0;
		while (!pq.empty()) {
			y = pq.top().second.first;
			x = pq.top().second.second;
			cost = -pq.top().first;
			pq.pop();
			if (is_parent(y, x))
				res += cost;
		}
		res *= E;
		printf("#%d %0.lf\n", tc, res);
	}
	return 0;
}