#include<iostream>
#include<vector>
#include<unordered_set>

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
        long long res = 2;
        while(true){
            unordered_set<int> s;
            for(int i = 0; i < n; i++){
                long long val =  arr[i] % res;
                s.insert(val);
            }
            if(s.size() == 2){
                cout << res << endl;
                break;
            }
            res *= 2;
        }
    }
    
}