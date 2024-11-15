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
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int res = INT_MAX;
        for(int i = 0; i < n; i++){
            if(i != a[i]){
                res &= a[i];
            }
        }
        cout << res << endl;
    }
}