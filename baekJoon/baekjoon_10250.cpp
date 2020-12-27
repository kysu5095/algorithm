// ACM 호텔 //
/////////////

#include <iostream>

using namespace std;

int main() {
	int T, H, W, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		int x = 1;
		while (N > H) {
			x++;
			N -= H;
		}
		cout << N;
		cout.width(2);
		cout.fill('0');
		cout << x << '\n';
	}

	//system("pause");
	return 0;
}
