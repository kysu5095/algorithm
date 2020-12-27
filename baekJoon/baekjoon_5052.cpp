// 전화번호 목록

#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Trie {
public:
	Trie* trie[11];
	bool is_end;
	Trie() {
		is_end = false;
		for (int i = 0; i < 11; i++)
			trie[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 11; i++)
			if (trie[i]) delete trie[i];
	}
	void insert(const string& str, const int& idx) {
		if (idx == str.length()) is_end = true;
		else {
			int num = str[idx] - '0';
			if (trie[num] == NULL)
				trie[num] = new Trie;
			trie[num]->insert(str, idx + 1);
		}
	}
	bool find(const string& str, const int& idx) {
		if (idx == str.length()) return false;
		if (is_end) return true;
		int num = str[idx] - '0';
		return trie[num]->find(str, idx + 1);
	}
};

int test_case, n;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> test_case;
	while (test_case--) {
		Trie *trie = new Trie;
		bool flag = true;
		cin >> n;
		vector<string> v;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			trie->insert(str, 0);
			v.push_back(str);
		}
		for (int i = 0; i < n; i++) {
			if (trie->find(v[i], 0)) {
				flag = false;
				break;
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
		delete trie;
	}
	return 0;
}