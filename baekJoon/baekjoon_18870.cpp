// 좌표 압축

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v.resize(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	
	int cnt = 0;
	int* arr = new int[n];
	arr[v[0].second] = 0;
	for(int i = 1; i < n; i++){
		if(v[i].first == v[i - 1].first) arr[v[i].second] = cnt;
		else arr[v[i].second] = ++cnt;
	}
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << '\n';
	return 0;
}
