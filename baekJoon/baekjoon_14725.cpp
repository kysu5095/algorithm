// 개미굴

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int n, k;
vector<string> v;

class Trie {
public:
	Trie* trie[16];
	map<string, int> m;
	int idx;
	Trie() {
		for (int i = 0; i < 16; i++) trie[i] = NULL;
		idx = 0;
	}
	~Trie() {
		for (int i = 0; i < 16; i++)
			if (trie[i])
				delete trie[i];
	}
	void insert(const vector<string>& v, const int cnt) {
		if (cnt == v.size()) {
			return;
		}
		else {
			if (!(m.count(v[cnt]))) {
				trie[idx] = new Trie;
				m[v[cnt]] = idx++;
			}
			trie[m.find(v[cnt])->second]->insert(v, cnt + 1);
		}
	}

	void find(int cnt) {
		if (m.empty()) return;
		map<string, int>::iterator iter = m.begin();
		while (iter != m.end()) {
			for (int i = 0; i < cnt; i++)
				cout << "--";
			cout << iter->first << '\n';
			trie[iter->second]->find(cnt + 1);
		}
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	Trie* trie = new Trie;
	cin >> n;
	while (n--) {
		cin >> k;
		for(int i = 0; i < k; i++) {
			string str = "";
			cin >> str;
			v.push_back(str);
		}
		trie->insert(v, 0);
		v.clear();
	}
	trie->find(0);
	return 0;
}