#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long long n,h;
    cin>>n>>h;
    vector<int> a(n);
    for(int i=0 ;i<n ;i++) cin >> a[i];

    int res = 0;
    int left = 1, right = n;

    while(left <= right){
        int mid = left + (right - left) / 2;
        vector<int> b(a.begin(), a.begin() + mid);
        sort(b.rbegin(), b.rend());

        long long sum = 0;
        for(int i=0;i<mid;i+=2){
            sum += b[i];
        }

        if(sum <= h){
            res = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }

    }
    cout << res << endl;
    return 0;
}