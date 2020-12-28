// 수도 요금 경쟁

#include <iostream>

using namespace std;

int main(){
    int test_case, p, q, r, s, w;
    cin >> test_case;
    for(int test = 0; test < test_case; test++){
        cin >> p >> q >> r >> s >> w;
        int cost1 = p * w;
        int cost2 = q;
        if(r < w)
            cost2 += ((w - r) * s);
        
        if(cost1 <= cost2)
            cout << "#" << test + 1 << " " << cost1 << endl;
        else
            cout << "#" << test + 1 << " " << cost2 << endl; 
    }
    return 0;
}