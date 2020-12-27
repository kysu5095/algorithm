// 이항계수 1 //
///////////////

#include <iostream>

using namespace std;

int factorial(int n){
    if(n == 0 || n == 1) return 1;
    else return factorial(n - 1) * n;
}

int main(){
    int n, k;
    cin >> n >> k;

    cout << factorial(n) / (factorial(k) * factorial(n - k)) << '\n';
    return 0;
}