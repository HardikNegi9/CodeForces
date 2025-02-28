#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int res = 0;
        for(int i = 1; i < n; i++){
            if(a[i] < a[i-1]){
                res = max(res, a[i-1] - a[i]);
                a[i] = a[i-1];
            }
        }


        cout << int(ceil(log2(res + 1))) << endl;

    }
}