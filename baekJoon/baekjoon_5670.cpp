// 휴대폰 자판

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v;

class Trie {
public:
	Trie* trie[26];
	int cnt;
	bool is_end;
	Trie() {
		for (int i = 0; i < 26; i++) trie[i] = 0;
		cnt = 0;
		is_end = false;
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (trie[i])
				delete trie[i];
	}
	void insert(const string& str, const int& idx) {
		if (idx == str.length()) {
			is_end = true;
			return;
		}
		int c = str[idx] - 'a';
		if (trie[c] == NULL) {
			trie[c] = new Trie;
			cnt++;
		}
		trie[c]->insert(str, idx + 1);
	}

	void find(const string& str, const int& idx, int& count) {
		if (idx == str.length()) return;
		int c = str[idx] - 'a';
		if (idx && (cnt > 1 || is_end)) count++;
		trie[c]->find(str, idx + 1, count);
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	string str;
	while (cin >> n) {
		Trie* trie = new Trie;
		for(int i = 0; i < n; i++){
			cin >> str;
			v.push_back(str);
			trie->insert(str, 0);
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int tmp = 1;
			trie->find(v[i], 0, tmp);
			cnt += tmp;
		}
		cout << fixed;
		cout.precision(2);
		cout << (double)cnt / n << '\n';
		delete trie;
		v.clear();
	}
	return 0;
}