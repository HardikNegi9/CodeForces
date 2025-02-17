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
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        int left = 0, right = n - 1;
        int alice = 0, bob = 0;
        int res = 0;
        while(left <= right){

            if(alice < bob){
                alice += a[left];
                left++;
            }else{
                bob += a[right];
                right--;
            }

            if(alice == bob){
                res = left + n - right - 1;
            }
        }
        cout << res << endl;
    }
}