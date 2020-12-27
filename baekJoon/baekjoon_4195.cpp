// 친구 네트워크
// 6:00

#include <iostream>
#include <string>
#include <map>

using namespace std;

int test_case, F;
int parent[100001], friend_n[100001];
map<string, int> m;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

int Union(int y, int x) {
	y = find(y);
	x = find(x);
	if (y > x) {
		parent[y] = x;
		friend_n[x] += friend_n[y];
		return friend_n[x];
	}
	else if(y < x){
		parent[x] = y;
		friend_n[y] += friend_n[x];
		return friend_n[y];
	}
	return friend_n[y];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> test_case;
	while (test_case--) {
		cin >> F;
		int idx = 1;
		for (int i = 0; i <= F; i++)
			parent[i] = i, friend_n[i] = 1;
		m.clear();
		for (int i = 0; i < F; i++) {
			string str1, str2;
			cin >> str1 >> str2;
			if (!m.count(str1)) m.insert(make_pair(str1, idx++));
			if (!m.count(str2)) m.insert(make_pair(str2, idx++));
			cout << Union(m[str1], m[str2]) << '\n';
		}
	}
	return 0;
}