#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool solve(int time, map<int, int> mp, int n){
    long long left = 0;
    long long available = 0;

    for(int i = 1; i <= n; i++){
        long long task = mp[i] - time;
        if(task < 0){
            available -= (task / 2);
        }else{
            left += task;
        }
    }

    return left <= available;

}



int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        map<int, int> mp;
        
        for(int i = 0; i < m; i++){
            cin >> a[i];
            mp[a[i]]++;
        }

        int left = 1, right = 2*m;
        int res = 2*m;
        while(left <= right){
            int mid = (left + right) / 2;
            
            if(solve(mid, mp, n)){
                right = mid - 1;
                res = mid;
            }else{
                left = mid + 1;
            }
        }


        cout << res << endl;

    }
}