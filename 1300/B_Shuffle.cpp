#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> k >> m;
        int left = k, right = k;

        while(m--){
            int l, r;
            cin >> l >> r;
            if(l > right || r < left) continue;
            left = min(left, l);
            right = max(right, r);
        }

        cout << right - left + 1 << endl;
        
    }
}




