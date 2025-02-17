#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool solve(long long mid, long long x, vector<long long>& a){
    long long cnt = 0;
    for(long long height : a){
        if(height < mid){
            cnt += mid - height;
        }
    }
    return cnt <= x;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, x;
        cin >> n >> x;
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        long long left = 1, right = x + *max_element(a.begin(), a.end());
        long long res = 0;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            if(solve(mid, x, a)){
                res = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        cout << res << endl;
    }
}