#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int e = 0;
        int d = k - 1;

        for(int i : a){
            if(i % 2 == 0){
                e++;
            }
            if(i % k == 0) d = 0;
            else d = min(d, k - (i % k));
        }


        if(k != 4) cout << d << endl;
        else
            if(e > 1) cout << 0 << endl;
            else if(e == 1) cout << min(1, d) << endl;
            else cout << min(2, d) << endl;
    }
}