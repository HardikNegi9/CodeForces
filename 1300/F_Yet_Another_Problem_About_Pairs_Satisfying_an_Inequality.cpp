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
        vector<int> b;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] < i + 1){
                b.push_back(i + 1);
            }
        }

        long long res = 0;
        for(int i : b){
            res += lower_bound(b.begin(), b.end(), a[i - 1]) - b.begin();
        }

        cout << res << endl;  
    }
}