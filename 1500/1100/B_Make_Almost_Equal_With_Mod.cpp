#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        long long max_val = *max_element(arr.begin(), arr.end());
        long long res = 2;
        
        while(res <= max_val * 2){
            unordered_set<long long> s;
            for(int i = 0; i < n; i++){
                long long val = arr[i] % res;
                s.insert(val);
            }
            
            if(s.size() == 2){
                cout << res << endl;
                break;
            }
            
            res *= 2ll;
        }
    }
    return 0;
}