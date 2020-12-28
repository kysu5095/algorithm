// 복습 2:00 시작
// 보물상자 비밀번호

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <deque>
#include <math.h>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int test_case, n, k;
int res;
deque<char> dq;
set<string, greater<string>> s;

bool desc(int f1, int f2) {
	return f1 > f2;
}

int calculate(char input) {
	if (49 <= input && input <= 57)
		return (input - 48);
	else if (65 <= input && input <= 70)
		return (input - 55);
	else
		return 0;
}

void lotate() {
	for (int i = 0; i < n / 4; i++) {
		string str;
		for (int j = 0; j < n; j++) {
			str += dq[j];
			if (j % (n / 4) == ((n / 4) - 1)) {
				s.insert(str);
				str.clear();
			}
		}
		dq.push_front(dq.back());
		dq.pop_back();
	}

	int idx = 0;
	set<string>::iterator iter = s.begin();
	for (iter; iter != s.end(); iter++) {
		idx++;
		if (idx == k)
			break;
	}
	string str = *iter;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		res += (pow(16, (len - 1) - i) * calculate(str[i]));
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	char input;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; tc++) {
		res = 0;
		dq.clear();
		s.clear();
		scanf(" %d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf(" %1c", &input);
			dq.push_back(input);
		}
		lotate();
		printf("#%d %d\n", tc, res);
	}
	return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <string>
// #include <deque>
// #include <set>
// #include <math.h>

// using namespace std;

// int n, k;
// int main() {
// 	freopen("input.txt", "r", stdin);
// 	int test_case;
// 	cin >> test_case;
// 	for (int tc = 1; tc <= test_case; tc++) {
// 		deque<char> dq;
// 		set<int> s;
// 		string str;
// 		cin >> n >> k;
// 		cin >> str;
// 		for (int i = 0; i < n; i++) dq.push_back(str[i]);
// 		for (int i = 0; i <= (n >> 2); i++) {
// 			int idx = 0;
// 			char next;
// 			for (int j = 0; j < 4; j++) {
// 				int val = 0, mul = (n >> 2) - 1;
// 				for (int k = 0; k < (n >> 2); k++) {
// 					next = dq[idx];
// 					if (next >= '0' && next <= '9') val += ((next - '0') * pow(16, mul));
// 					else val += (((next - 'A') + 10) * pow(16, mul));
// 					idx++;
// 					mul -= 1;
// 				}
// 				s.insert(-val);
// 			}
// 			dq.push_front(dq.back());
// 			dq.pop_back();
// 		}
// 		int idx = 0;
// 		set<int>::iterator iter = s.begin();
// 		for (iter; iter != s.end(); iter++) {
// 			if (idx++ == k - 1) {
// 				cout << "#" << tc << " " << -(*iter) << '\n';
// 				break;
// 			}
// 		}
// 	}
// }