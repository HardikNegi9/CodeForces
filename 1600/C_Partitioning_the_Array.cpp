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
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int res = 0;
        for(int k = 1; k <= n; k++){
            if(n % k == 0){
                
                int g = 0;
                for(int i = 0; i + k < n; i++){
                    g = __gcd(g, abs(a[i] - a[i + k]));
                }

                res += (g != 1);
            }
        }

        cout << res << endl;
    }
}
