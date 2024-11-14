#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int _gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return _gcd(b, a%b);
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> vec(n);
        for(int i=0; i<n; i++){
            cin >> vec[i];
        }

        unordered_map<int, int> map;
        for(int i = 0; i < n; i++){
            map[vec[i]] = i + 1;
        }

        int res = -1;
        for(auto [el1, i]: map){
            for(auto [el2, j] : map){
                if(_gcd(el1, el2) == 1){
                    res = max(res, i + j);
                }
            }
        }

        cout << res << endl;

    }
}