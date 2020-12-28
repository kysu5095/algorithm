// 늘어지는 소리 만들기

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case, h, lo, len;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		string word;
		vector<char> v[21];
		cin >> word;
		len = word.length();
		for (int i = 1; i <= len; i++)
			v[i].push_back(word[i - 1]);
		
		cin >> h;
		for (int i = 0; i < h; i++) {
			cin >> lo;
			v[lo].push_back('-');
		}
		
		cout << "#" << tc << " ";
		for (int i = 0; i <= len; i++) {
			if (!v[i].empty()) {
				int v_len = v[i].size();
				for (int j = 0; j < v_len; j++)
					cout << v[i][j];
			}
		}
		cout << '\n';
	}

	return 0;
}