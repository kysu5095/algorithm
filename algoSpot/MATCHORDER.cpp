#include <iostream>
#include <algorithm>

using namespace std;

int C, n;
int russia[101], korea[101];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	int idx, res;
	cin >> C;
	while(C--){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> russia[i];
		for(int i = 0; i < n; i++) cin >> korea[i];
		sort(russia, russia + n);
		sort(korea, korea + n);
		idx = res = 0;
		for(int i = 0; i < n; i++){
			while(idx != n && russia[i] > korea[idx]) idx++;
			if(idx == n) break;
			idx++;
			res++;
		}
		cout << res << '\n';
	}
	return 0;
}
