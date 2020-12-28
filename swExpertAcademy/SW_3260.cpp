// 두 수의 덧셈

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test_case;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; tc++) {
		int len_a, len_b, add_a, add_b, add_sum, addition = 0;
		deque<int> dq;
		string a, b, tmp, res;
		cin >> a >> b;
		len_a = a.length(), len_b = b.length();
		if (len_a < len_b) {
			tmp = a;
			a = b;
			b = tmp;
		}
		while (len_a-- > 0) {
			add_a = a[len_a] - '0';
			if (len_b-- > 0) add_b = b[len_b] - '0';
			else add_b = 0;

			add_sum = add_a + add_b + addition;
			if (add_sum / 10 == 1) addition = 1;
			else addition = 0;
			add_sum %= 10;
			dq.push_front(add_sum);
		}
		if(addition == 1)
			dq.push_front(addition);

		int len = dq.size();
		cout << "#" << tc << " ";
		for (int i = 0; i < len; i++)
			cout << dq[i];
		cout << '\n';
	}
	return 0;
}