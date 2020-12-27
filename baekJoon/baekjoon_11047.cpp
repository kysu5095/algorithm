// 동전 0 //
///////////

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int cnt = 0;
int n, k;

int greedy(int n){
    for(int i = v.size() - 1; i >= 0; i--){
        while(k - v[i] >= 0){
            k -= v[i];
            cnt++;
            if(k == 0) break;
        }
    }
    if(k != 0) return 0;
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    cout << greedy(k) << endl;

    return 0;
}