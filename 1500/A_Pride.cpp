#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;



int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int ones = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 1){
            ones++;
        }
    }

    if(ones > 0){
        cout << n - ones << endl;
        return 0;
    }


    int len = INT_MAX;
    for(int i = 0; i < n; i++){
        int gcd = a[i];
        for(int j = i; j < n; j++){
            gcd = __gcd(gcd, a[j]);

            if(gcd == 1){
                len = min(len, j - i);
                break;
            }
        }
    }

    if(len == INT_MAX){
        cout << -1 << endl;
    }else{
        cout << len + n - 1 << endl;
    }
}