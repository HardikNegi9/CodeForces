#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std; 

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<pair<int, int>> power(n);
        for(int i=0; i<n; i++){
            int k;
            cin >> k;
            int maxv = -1;
            for(int j = 0; j < k; j++){
                int x;
                cin >> x;
                maxv = max(maxv, x - j + 1);
            }

            power[i] = {maxv, k};
        }

        sort(power.begin(), power.end());

        function<bool(int)> solve = [&](int x) -> bool{
            for(int i=0; i<n; i++){
                if(power[i].first > x) return false;
                x += power[i].second;
            }
            return true;
        };


        int res = 1;
        int left = 1, right = power[n - 1].first + 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(solve(mid)){
                res = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        cout << res << endl;

    }
}