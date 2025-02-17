#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> a(n + 1);

        for(int i=1; i<=n; i++){
            cin >> a[i];
        }

        int count = 0;

        for(long long i = 1; i <= n; i++){
            for(long long j = a[i] - i ; j <= n; j += a[i]){
                if(j >= 0 && i + j == a[i]*a[j] & i < j){
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}