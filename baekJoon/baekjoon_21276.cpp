// 계보 복원가 호석

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int n, k;
int in[1001];
vector<int> v[1001];
vector<string> input, grand, children[1001];
map<string, int> m;
queue<int> q;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int idx = 0;
	cin >> n;
	input.resize(n);
	for (int i = 0; i < n; i++) cin >> input[i];
	sort(input.begin(), input.end());
	for (int i = 0; i < n; i++) m[input[i]] = i;

	cin >> k;
	for (int i = 0; i < k; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		v[m[str2]].push_back(m[str1]);
		in[m[str1]]++;
	}
	for (int i = 0; i < n; i++) {
		if (!in[i]) {
			grand.push_back(input[i]);
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto& next : v[cur]) {
			in[next]--;
			if (in[next] == 0) {
				q.push(next);
				children[cur].push_back(input[next]);
			}
		}
	}

	cout << grand.size() << '\n';
	for (auto& it : grand) cout << it << " ";
	cout << '\n';
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << children[m[it->first]].size() << " ";
		sort(children[m[it->first]].begin(), children[m[it->first]].end());
		for (auto& str : children[m[it->first]]) cout << str << " ";
		cout << '\n';
	}

	return 0;
}