#include<iostream>
#include<vector>
using namespace std;

long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        long long gcd1 = 0;
        long long gcd2 = 0;

        for(int i = 0; i < n; i+=2) gcd2 = gcd(gcd2, a[i]);

        for(int i = 1; i < n; i+=2) gcd1 = gcd(gcd1, a[i]);

        bool flag = true;
        for(int i = 0; i < n; i+=2){
            if(a[i] % gcd1 == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << gcd1 << endl;
            continue;
        }

        flag = true;
        for(int i = 1; i < n; i+=2){
            if(a[i] % gcd2 == 0){
                flag = false;
                break;
            }
        }

        if(flag){
            cout << gcd2 << endl;
            continue;
        }
        cout << 0 << endl;
    }
}