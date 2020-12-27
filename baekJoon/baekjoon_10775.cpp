// 공항

#include <iostream>
#include <string.h>

using namespace std;

int G, P;
int arr[100001];

int find(int x) {
	if (arr[x] < 0) return x;
	return arr[x] = find(arr[x]);
}

void Unoion(int y, int x) {
	y = find(y);
	x = find(x);
	if (y == x) return;
	arr[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int plane, gate, res = 0;
	bool flag = false;
	memset(arr, -1, sizeof(arr));
	cin >> G >> P;
	for (int i = 0; i < P; i++) {
		cin >> plane;
		if (flag) continue;
		gate = find(plane);
		if (!gate) { flag = true; continue; }
		Unoion(gate, gate - 1);
		res++;
	}
	cout << res << '\n';
	return 0;
}