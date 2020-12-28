// 제로

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case, k;
    cin >> test_case;
    for(int tc = 1; tc <= test_case; tc++){
        int input, sum = 0;
        vector<int> v;
        cin >> k;
        for(int i = 0; i < k; i++){
            cin >> input;
            if(input == 0){
                sum -= v.back();
                v.pop_back();
            }
            else{
                sum += input;
                v.push_back(input);
            }
        }
        cout << "#" << tc << " " << sum << '\n';
    }

    return 0;
}