#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int zero = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] % 10 == 0){
                zero++;
            }else if(a[i] % 10 == 5){
                zero++;
                a[i] += 5;
            }else{
                while(a[i] % 10 != 2){
                    a[i] += a[i] % 10;
                }
            }
        }

        sort(a.begin(), a.end());

        if(zero == n){
            cout << (a[0] == a[n - 1] ? "Yes" : "No") << endl;
        }else{
            bool flag = true;
            for(int i = 1; i < n && flag; i++){
                int diff = a[i] - a[i - 1];
                if(diff % 20 != 0) flag = false;
            }

            if(flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}