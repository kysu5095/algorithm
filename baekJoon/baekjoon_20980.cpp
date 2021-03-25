// pancake

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int n, m;
queue<int> q;

int string_to_int(string& str) {
	int res = 0;
	for (int i = 0; i < n; i++)
		res = res * 3 + (str[i] - 'A');
	return res;
}

string int_to_string(int& val) {
	string res = "";
	while (val) {
		res += ((val % 3) + 'A');
		val /= 3;
	}
	while (res.length() != n) res += 'A';
	reverse(res.begin(), res.end());
	return res;
}

vector<int> make_all() {
	vector<int> visited(pow(3, n) + 1, -1);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; i + j <= n; j++) {
			string str = string(i, 'A') + string(j, 'B') + string(n - i - j, 'C');
			int val = string_to_int(str);
			q.push(val);
			visited[val] = 0;
		}
	}
	return visited;
}

void bfs(vector<int>& visited) {
	int len, t = 0;
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			int node = q.front();
			q.pop();
			string str = int_to_string(node);
			for (int i = 2; i <= n; i++) {
				string next_str = str;
				reverse(next_str.begin(), next_str.begin() + i);
				int next_node = string_to_int(next_str);
				if (visited[next_node] == -1) {
					q.push(next_node);
					visited[next_node] = t;
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector<int> visited = make_all();
	bfs(visited);
	while (m--) {
		string str;
		cin >> str;
		cout << visited[string_to_int(str)] << '\n';
	}
	return 0;
}