// 집합의 표현
// 5:10

#include <iostream>

using namespace std;

int n, m;
int arr[1000001];

int find_parent(int x) {
	if (arr[x] == x) return x;
	return arr[x] = find_parent(arr[x]);
}

void union_parent(int y, int x) {
	y = find_parent(y);
	x = find_parent(x);
	if (y == x) return;
	if (y > x) arr[y] = x;
	else arr[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int command, node1, node2;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		arr[i] = i;
	while (m--) {
		cin >> command >> node1 >> node2;
		if (command) {
			if (find_parent(node1) == find_parent(node2))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else 
			union_parent(node1, node2);
	}
	return 0;
}