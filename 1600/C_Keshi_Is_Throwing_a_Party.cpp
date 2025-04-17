#include<iostream>
#include<vector>
using namespace std;


bool solve(vector<pair<int, int>>& a, int mid){
    int n = a.size();

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(mid - cnt - 1 <= a[i].first && cnt <= a[i].second){
            cnt++;
        }
    }

    return cnt >= mid;
}



int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].first >> a[i].second;
        }

        int res = 0;
        
        int low = 0, high = n;
        
        while(low <= high){
            int mid = (low + high) / 2;
            

            if(solve(a, mid)){
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << res << endl;
    }
}