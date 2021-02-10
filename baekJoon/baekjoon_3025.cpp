// 돌 던지기 

#include <iostream>
#include <set>

int r, c;
char arr[30001][31];
set<int> s[31];

using namespace std;

void print(){
	for(int i = 0; i < r; i++)
		cout << arr[i] << '\n';
}

void throw_stone(int x){
	int cur_y = 0, y = 0;
	set<int>::iterator iter;
	while(true){
		if(s[x].empty()){
			arr[r-1][x] = 'O';
			s[x].insert(r-1);
			break;
		}
		for(iter = s[x].begin(); iter != s[x].end(); iter++){
			cur_y = *iter;
			if(cur_y <= y) continue;
			y = cur_y;
			break;
		}
		if(iter == s[x].end()){
			arr[r-1][x] = 'O';
			s[x].insert(r-1);
			break;
		}
		if(arr[y][x] == 'X'){
			arr[y-1][x] = 'O';
			s[x].insert(y-1);
			break;
		}
		if(x > 0 && arr[y][x-1] == '.' && arr[y+1][x-1] == '.'){
			x--;
			continue;
		}
		if(x < c-1 && arr[y][x+1] == '.' && arr[y+1][x+1] == '.'){
			x++;
			continue;
		}
		arr[y-1][x] = 'O';
		s[x].insert(y-1);
		break;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		cin >> arr[i];
		for(int j = 0; j < c; j++)
			if(arr[i][j] == 'X')
				s[j].insert(i);
	}
	int t, col;
	cin >> t;
	while(t--){
		cin >> col;
		throw_stone(col);
	}
	print();
	return 0;
}