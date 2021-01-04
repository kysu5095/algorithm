// 원주율 외우기

#include <iostream>
#include <string>
#include <string.h>
#include <limits.h>
#include <algorithm>
#include <math.h>

using namespace std;

int C;
int arr[10001];
int cache[10001];
string str;

int get_score(int start, int last) {
	bool all_number_same = true;
	for (int i = start + 1; i <= last; i++) {
		if (arr[i] != arr[start]) {
			all_number_same = false;
			break;
		}
	}
	if (all_number_same) return 1;

	bool up_down_number = true;
	for (int i = start; i < last; i++) {
		if (arr[i + 1] - arr[i] != arr[start + 1] - arr[start]) {
			up_down_number = false;
			break;
		}
	}
	if (abs(arr[start + 1] - arr[start]) == 1 && up_down_number) return 2;

	bool only_two_number = true;
	for (int i = start + 2; i <= last; i++) {
		if (arr[i] != arr[i - 2]) {
			only_two_number = false;
			break;
		}
	}
	if (only_two_number) return 4;
	if (up_down_number) return 5;
	return 10;
}

int get_level(int start) {
	if (start == str.length()) return 0;
	int& ret = cache[start];
	if (ret) return ret;
	ret = 987654321;
	for (int i = 3; i <= 5; i++) {
		if (start + i <= str.length())
			ret = min(ret, get_level(start + i) + get_score(start, start + i - 1));
 	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> C;
	while (C--) {
		memset(arr, 0, sizeof(arr));
		memset(cache, 0, sizeof(cache));
		cin >> str;
		for (int i = 0; i < str.length(); i++)
			arr[i] = (str[i] - '0');
		cout << get_level(0) << '\n';
	}
	return 0;
}