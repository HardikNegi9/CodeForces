#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        vector<long long> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        vector<long long> pre(n);
        pre[0] = arr[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] + arr[i];
        }

        long long prev = arr[0] * b;
        long long res = pre[n - 1] * b;

        for(int i = 0; i < n; i++){

            long long temp = prev + arr[i]*a + (pre[n - 1] - pre[i] - (n - 1 - i) * arr[i])*b;
            res = min(res, temp);
            
            if(i == n - 1) break;
            prev += (arr[i + 1] - arr[i])*b;

        }

        cout << res << endl;


    }
}