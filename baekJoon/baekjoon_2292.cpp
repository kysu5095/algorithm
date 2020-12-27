//  벌집 //
//////////

#include <iostream>

using namespace std;

int main() {
	long int N;
	long int path = 1;
	long int branch = 1;
	cin >> N;

	while (branch < N) {
		branch += path++ * 6;
	}
	
	cout << path << '\n';
	//system("pause");
	return 0;
}