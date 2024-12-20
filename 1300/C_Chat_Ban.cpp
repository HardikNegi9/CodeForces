#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long x, k;
        cin >> k >> x;

        long long res = 1;
        long long left = 1;
        long long right = 2*k - 1;

        

        while(left <= right){
            long long mid = left + (right - left) / 2;
            long long sum = 0;
            if(mid <= k){
                sum = (mid *(mid + 1)) / 2;
            }else{
                long long rem = 2*k - mid - 1;
                sum = ((k * (k + 1)) / 2) + ((k * (k - 1)) / 2 - (rem * (rem + 1)) / 2);
            }

            if(sum == x){
                res = mid;
                break;
            }else if(sum > x){
                right = mid - 1;
            }else{
                res = mid + 1;
                left = mid + 1;
            }
        }

        cout << min(res, 2*k - 1) << endl;
    }
}