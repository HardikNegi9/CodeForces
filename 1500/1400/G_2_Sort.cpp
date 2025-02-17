#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int count = 1;
        int res = 0;
        
        for(int i = 1; i < n; i++){
            if(a[i - 1] < a[i] * 2ll){
                count++;
            }else{
                count = 1;
            }

            if(count > k){
                res++;
            }
        }

        cout << res << endl;
    }
}