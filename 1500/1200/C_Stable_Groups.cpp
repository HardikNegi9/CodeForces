#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long long n, x, k;
    cin >> n >> k >> x;

    vector<long long> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    vector<long long> diff;
    for(int i = 1; i < n; i++){
        diff.push_back(a[i] - a[i - 1]);
    }
    sort(diff.begin(), diff.end());
    int res = 1;

    for(int i = 0; i < diff.size(); i++){
        if(diff[i] > x){
            long long count = (diff[i] - 1) / x;
            if(k - count >= 0){
                k -= count;
            }else{
                res++;
            }
        }
    }

    cout << res << endl;
}
