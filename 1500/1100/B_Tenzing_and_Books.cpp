#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, x;
        cin >> n >> x;

        vector<long long> a(n), b(n), c(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        for(int i = 0; i < n; i++){
            cin >> c[i];
        }

        int i = 0, j = 0, k = 0;
        long long sum1 = 0, sum2 = 0, sum3 = 0;
        while(i < n && (x | a[i]) == x){
            sum1 |= a[i];
            i++;
        }
        while(j < n && (x | b[j]) == x){
            sum2 |= b[j];
            j++;
        }
        while(k < n && (x | c[k]) == x){
            sum3 |= c[k];
            k++;
        }
        if((sum1 | sum2 | sum3) == x) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}