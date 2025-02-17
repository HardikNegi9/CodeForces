#include<iostream>
#include<vector>
using namespace std;

long long sq(long long x){
    return x * x;
}


int solve(long long w, long long c, vector<long long>& a){
    long long cnt = 0;
    for(long long i : a){
        cnt += sq(i + (2*w));
        if(cnt > c) break;
    }
    return cnt <= c;

}



int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, c;
        cin >> n >> c;
        vector<long long> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        long long left = 1, right = 1e9;
        int res = 0;
        while(left <= right){
            long long mid = left + (right - left) / 2;

            if(solve(mid, c, a)){
                res = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        cout << res << endl;
    }
}