#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b){
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
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int left = 0;
        int right = n - 1;
        int res = 0;
        while(left <= right){
            if(a[left] == a[right]){
                left++;
                right--;
            }
            else{
                res = gcd(res, abs(a[left] - a[right]));
                left++;
                right--;
            }
        }

        cout << res << endl;
    }
}