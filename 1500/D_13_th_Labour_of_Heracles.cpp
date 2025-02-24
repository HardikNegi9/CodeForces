#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<long long> nums(n + 1);

        vector<int> count(n + 1, 0);
        long long res = 0;

        for(int i = 1; i <= n; i++){
            cin >> nums[i];
            res += nums[i];
        }
        
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;

            count[u]++;
            count[v]++;
        }
        
        vector<int> ele;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < count[i] - 1; j++){
                ele.push_back(nums[i]);
            }
        }

        sort(ele.begin(), ele.end(), greater<long long>());
        
        cout << res;
        for(int i = 0; i < n - 2; i++){
            res += ele[i];
            cout << " " << res;
        }
        
        cout << endl;

    }
}