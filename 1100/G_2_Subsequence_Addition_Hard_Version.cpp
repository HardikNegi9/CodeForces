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
        vector<long long> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        if(arr[0] != 1){
            cout << "NO" << endl;
            continue;
        }
        long long sum = arr[0];
        bool flag = true;
        for(int i = 1; i < n; i++){
            if(arr[i] > sum){
                flag = false;
                break;
            }
            sum += arr[i];
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}