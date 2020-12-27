//  ATM  //
///////////

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int sum = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int time;
        cin >> time;
        v.push_back(time);
    }
    sort(v.begin(), v.end());   // nlogn
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j <= i; j++){
            sum += v[j];
        }
    }

    cout << sum << '\n';

    return 0;
}