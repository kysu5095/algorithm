// 100만 이하의 모든 소수

/////////////////////
///  버러지 코드   ///
/////////////////////

//#include <iostream>
//#include <list>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	list<int> arr;
//	arr.push_front(2);
//	list<int>::iterator iter;
//	bool flag = true;
//	for (int i = 3; i <= 50000; i++) {
//		iter = arr.begin();
//		while (iter != arr.end()) {
//			if (i % *(iter++) == 0) {
//				flag = false;
//				break;
//			}
//		}
//		if (flag == true)
//			arr.push_back(i);
//		else
//			flag = true;
//	}
//	iter = arr.begin();
//	while (iter != arr.end())
//		cout << *(iter++) << " ";
//
//	return 0;
//}

#define NUM 1000000
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	int* arr = new int[NUM];
	int* res = new int[NUM];
	int idx = 0;
	for (int i = 2; i <= NUM; i++)
		arr[i] = i;
	for (int i = 2; i <= NUM; i++) {
		if (arr[i] == 0)
			continue;
		res[idx++] = i;
		for (int j = i * 2; j <= NUM; j += i)
			arr[j] = 0;
	}
	for (int i = 0; i < idx; i++)
		printf("%d ", res[i]);
	
	delete[] arr, res;
	return 0;
}