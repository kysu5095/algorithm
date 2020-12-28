// 두 개의 숫자열

#include <iostream>

using namespace std;

int arr1[21];
int arr2[21];
int n, m;

int numString(){
    int max = 0;
    int maxValue = 0;
    int minLen, maxLen;
    minLen = n >= m ? m : n;
    maxLen = n <= m ? m : n;

    for(int jud = 0; jud <= maxLen - minLen; jud++){
        for(int i = 0; i < minLen; i++){
            if(n >= m){
                maxValue += arr1[i + jud] * arr2[i]; 
            }
            else{
                maxValue += arr1[i] * arr2[i + jud];
            }
        }
        max = max > maxValue ? max : maxValue;
        maxValue = 0;
    }

    return max;
}

int main(){
    int test_case;

    cin >> test_case;
    for(int i = 0; i < test_case; i++){
        cin >> n >> m;
        for(int j = 0; j < n; j++) cin >> arr1[j];
        for(int k = 0; k < m; k++) cin >> arr2[k];

        cout << "#" << i + 1 << " " << numString() << '\n';
    }

    return 0;
}