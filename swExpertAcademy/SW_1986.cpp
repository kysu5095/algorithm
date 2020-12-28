// 지그재그 숫자

#include <iostream>

using namespace std;

int test_case, n;

int main(){
    cin >> test_case;
    for(int i = 0; i < test_case; i++){
        cin >> n;
        int sum = 1;
        for(int j = 1; j < n; j++){
            if(j % 2 == 0)
                sum += j + 1;
            else
                sum -= j + 1;
        }
        cout << "#" << i + 1 << " " << sum << endl;
    }
    return 0;
}