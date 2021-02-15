// 친구 네트워크

#include <iostream>
#include <string>
#include <map>
#define MAX 200005

using namespace std;

int n;
int arr[MAX + 1], sz[MAX + 1];

void init() {
	for (int i = 1; i <= MAX; i++) {
		arr[i] = i;
		sz[i] = 1;
	}
}

int Find(int x) {
	if (x == arr[x]) return x;
	return arr[x] = Find(arr[x]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		init();
		int idx = 1;
		map<string, int> m;
		for (int i = 0; i < n; i++) {
			string name1, name2;
			cin >> name1 >> name2;
			if (m.find(name1) == m.end()) m[name1] = idx++;
			if (m.find(name2) == m.end()) m[name2] = idx++;

			int y = Find(m[name1]);
			int x = Find(m[name2]);
			if (y > x) swap(y, x);
			if (y != x) {
				arr[x] = y;
				sz[y] += sz[x];
			}
			cout << sz[y] << '\n';
		}
	}
	return 0;
}