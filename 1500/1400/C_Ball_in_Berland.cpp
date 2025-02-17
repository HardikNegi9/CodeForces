#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, k;
        cin >> a >> b >> k;
        vector<int> boys(k);
        vector<int> girls(k);
        vector<int> cnt1(a + 1, 0), cnt2(b + 1, 0);

        for(int i = 0; i < k; i++){
            cin >> boys[i];
            cnt1[boys[i]]++;
        }

        for(int i = 0; i < k; i++){
            cin >> girls[i];
            cnt2[girls[i]]++;
        }

        long long res = 0;
        for(int i = 0; i < k; i++){
            res += k - (cnt1[boys[i]] + cnt2[girls[i]]) + 1;
        }

        res /= 2;
        cout << res << endl;
    }
}