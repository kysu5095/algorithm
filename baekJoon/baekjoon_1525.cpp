// 퍼즐

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
//#define SIZE 9876543210
#define ANSWER "123456780"

using namespace std;

set<int> visited;
//bool visited[SIZE + 1];
int d[4] = { 1, -1, 3, -3 };

int bfs(string str) {
	if (str == ANSWER) return 0;
	int x, nx, num, len, t = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0') {
			x = i;
			break;
		}
	}
	queue<pair<int, string>> q;
	q.push(make_pair(x, str));
	//visited[stoi(_str)] = true;
	visited.insert(stoi(str));
	while (!q.empty()) {
		t++;
		len = q.size();
		while (len--) {
			x = q.front().first;
			str = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				if (i == 0 && (x == 2 || x == 5)) continue;
				if (i == 1 && (x == 3 || x == 6)) continue;
				nx = x + d[i];
				if (nx < 0 || nx > 8) continue;
				swap(str[x], str[nx]);
				if (str == ANSWER) return t;
				num = stoi(str);
				if (visited.find(num) == visited.end()) {
				//if (!visited[num]) {
					q.push(make_pair(nx, str));
					//visited[num] = true;
					visited.insert(num);
				}
				swap(str[x], str[nx]);
			}
		}
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string str = "";
	char ch;
	for (int i = 0; i < 9; i++) {
		cin >> ch;
		str += ch;
	}
	cout << bfs(str) << '\n';
	return 0;
}