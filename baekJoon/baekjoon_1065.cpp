//     한수     //
/////////////////

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

bool judge(int i);

int main() {
	int n, count = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (judge(i))   // distinguish
			count++;
	}

	cout << count << '\n';

	//system("pause");
	return 0;
}

bool judge(int i) {
	string str = to_string(i);  // convert string to int

	if (str.length() == 1 || str.length() == 2) {   // 한자리나 두자리수는 한수다
		return true;
	}
	else if (str.length() == 4)  return false;  // 4자리수는 1000밖에 없음
	else {
		int comp = str[2] - str[1];
		if (str[1] - str[0] != comp)	return false;
		return true;
	}
}