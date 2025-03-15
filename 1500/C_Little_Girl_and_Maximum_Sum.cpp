#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<int> b(n);
    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;

        b[l]++;
        if(r + 1 < n) b[r + 1]--;
    }

    for(int i = 1; i < n; i++){
        b[i] += b[i - 1];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += (long long)a[i] * b[i];
    }

    cout << sum << endl;
}