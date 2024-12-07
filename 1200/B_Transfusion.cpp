#include<iostream>
#include<vector>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n + 1);
        long long odd = 0;
        long long even = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(i&1) odd += a[i];
            else even += a[i];
        }

        int o = (n + 1) / 2;
        int e = n / 2;

        if(odd % o == 0 && even % e == 0 && odd / o  == even / e){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
}