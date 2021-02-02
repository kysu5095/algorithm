// 묘수풀이: 모독

#include <iostream>
#include <string.h>

using namespace std;

int n, m;
bool finish = false;
int arr[2][7][2];  // ATTACK, HP
int sequence[7];
int attack[8];
bool visited[7];

void COPY_ARR(int tmp[][7], bool flag){
	if(flag){
		for(int i = 0; i < n; i++) tmp[0][i] = arr[0][i][1];
		for(int i = 0; i < m; i++) tmp[1][i] = arr[1][i][1];
	}
	else{
		for(int i = 0; i < n; i++) arr[0][i][1] = tmp[0][i];
		for(int i = 0; i < m; i++) arr[1][i][1] = tmp[1][i];
	}
}

void LOG(int modok){
	int cnt;
	if(modok >= 0) cnt = 1;
	else cnt = 0;
	for(int i = 0; i < n; i++)
		if(attack[i] != -1) cnt++;
	cout << cnt << '\n';

	for(int i = 0; i < n; i++){
		if(i == modok) cout << "use modok\n";
		if(attack[i] != -1) cout << "attack " << sequence[i] << " " << attack[i] << '\n';
	}
}

bool PROMISING(){
	bool flag = true;
	for(int i = 0; i < m; i++)
		if(arr[1][i][1] > 0) flag = false;
		
	return flag;
}

void MODOK(){
	bool flag = true;
	while(flag){
		flag = false;
		for(int i = 0; i < n; i++)
			if(--arr[0][i][1] == 0) flag = true;
		for(int i = 0; i < m; i++)
			if(--arr[1][i][1] == 0) flag = true;
	}
}

void DFS(int _idx, int modok){
	if(finish) return;
	if(_idx == n){
		if(PROMISING()){
			LOG(modok);	
		}	
		return;
	}
	int tmp_arr[2][7];
	if(modok == -1){
		COPY_ARR(tmp_arr, true);
		MODOK();
		DFS(_idx, _idx);
		COPY_ARR(tmp_arr, false);
	}
	int idx = sequence[_idx];
	for(int i = 0; i < m; i++){
		if(arr[0][idx][1] > 0 && arr[1][i][1] > 0){
			attack[_idx] = i;
			arr[0][idx][1] -= arr[1][i][0];
			arr[1][i][1] -= arr[0][idx][0];
			DFS(idx + 1, modok);
			arr[0][idx][1] += arr[1][i][0];
			arr[1][i][1] += arr[0][idx][0];
		}
	}
	attack[_idx] = -1;
	DFS(idx + 1, modok);
}

void SEQUENCE(int idx){
	if(finish) return;
	if(idx == n){
		DFS(0, -1);
		return;
	}
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			visited[i] = true;
			sequence[idx] = i;
			SEQUENCE(idx + 1);
			visited[i] = false;
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> arr[0][i][0] >> arr[0][i][1];
	for(int i = 0; i < m; i++)
		cin >> arr[1][i][0] >> arr[1][i][1];
	memset(attack, -1, sizeof(attack));
	if(!n || !m) cout << "0\n";
	else {
		SEQUENCE(0);
		if(!finish)
			cout << "-1\n";
	}
	return 0;
}
