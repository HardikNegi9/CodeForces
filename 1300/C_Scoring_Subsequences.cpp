#include<iostream>
#include<vector>
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

        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++){
            int left = 0, right = i;
            int res = 0;
            while(left <= right){
                int mid = left + (right - left)/2;
                int val = a[mid] / (i - mid + 1);
                if(val){
                    res = mid;
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
            dp[i] = i - res + 1;
        }

        for(int i = 0; i < n; i++){
            cout << dp[i] << " ";
        }
        cout << endl;
    }
}