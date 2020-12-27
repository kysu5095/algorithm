// 광고

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int len, max_v = 0;
	string str;
	cin >> len >> str;
	int *arr = (int*)malloc(sizeof(int) * len);
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && str[i] != str[j])
			j = arr[j - 1];
		if (str[i] == str[j]) {
			arr[i] = ++j;
			//max_v = max_v < j ? j : max_v;
		}
	}
	//cout << len - max_v << '\n';
	cout << len - arr[len - 1] << '\n';
	return 0;
}