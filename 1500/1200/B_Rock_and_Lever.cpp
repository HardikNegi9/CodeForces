#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        long long res = 0;
        vector<bool> checked(n, 0);
        for(int i = 31; i >= 0; i--){
            long long cnt = 0;
            for(int j = 0; j < n; j++){
                if((arr[j] & (1 << i)) && !checked[j]){
                    cnt++;
                    checked[j] = 1;
                }
            }
            res += cnt * (cnt - 1) / 2;
        }

        cout << res << endl;
    }
}