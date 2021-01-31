// 신규 아이디 추천
// 3:45 - 4:10

#include <iostream>
#include <string>

using namespace std;

void level_1(string& str) {
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
	}
}

void level_2(string& str) {
	int len = str.size();
	string tmp;
	for (int i = 0; i < len; i++) {
		char ch = str[i];
		if ((ch >= 'a' && ch <= 'z') || ((ch - '0') >= 0 && (ch - '0') <= 9) || ch == '-' || ch == '_' || ch == '.')
			tmp.push_back(ch);
	}
	str.clear();
	str = tmp;
}

void level_3(string& str) {
	string tmp;
	int len = str.size();
	int left, right;
	for (int i = 0; i < len; i++) {
		if (str[i] == '.') {
			int j;
			for (j = i + 1; j < len; j++)
				if (str[j] != '.') break;
			tmp.push_back(str[i]);
			i = j - 1;
		}
		else tmp.push_back(str[i]);
	}
	str.clear();
	str = tmp;
}

void level_4(string& str) {
	if (str.empty()) return;
	if (str.front() == '.')
		str = str.substr(1);
	if (str.back() == '.')
		str = str.substr(0, str.size() - 1);
}

void level_5(string& str) {
	if (str.empty())
		str = "a";
}

void level_6(string& str) {
	int len = str.size();
	if (len >= 16) {
		str = str.substr(0, 15);
		if (str.back() == '.')
			str = str.substr(0, 14);
	}
}

void level_7(string& str) {
	int len = str.size();
	if (len <= 2) {
		while (len != 3) {
			str.push_back(str.back());
			len++;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string new_id;
	cin >> new_id;
	level_1(new_id);
	level_2(new_id);
	level_3(new_id);
	level_4(new_id);
	level_5(new_id);
	level_6(new_id);
	level_7(new_id);
	return 0;
}
