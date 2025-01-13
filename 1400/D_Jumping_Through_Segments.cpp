#include<iostream>
#include<vector>
using namespace std;

bool solve(int k, vector<pair<int, int>> &v){
    int l = 0, r = 0;
    for(int i = 0; i < v.size(); i++){
        l = max(l - k, v[i].first);
        r = min(r + k, v[i].second);
        if(l > r) return false;
    }
    return true;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].first >> v[i].second;
        }

        int res = 0;
        int left = 0, right = 1e9;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(solve(mid, v)){
                res = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        cout << res << endl;
    }
}