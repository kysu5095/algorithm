#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int arr[100001]{0, };
int n = 0;

int main(){
    ios_base::sync_with_stdio;
    cin.tie(0);

    int k = 0;
    int sum = 0;
    cin >> k;
    
    for(int i = 0; i < k; i++){
        int num = 0;
        cin >> num;

        if(num != 0){
            arr[n++] = num;
        }
        else{
            if(n != 0){
                arr[--n] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        sum += arr[i];
    }

    cout << sum << endl;

    return 0;
}