#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i].first;
            if(nums[i].first % k == 0)
                nums[i].first = k;
            else
                nums[i].first %= k;
            nums[i].second = i + 1;
        }

        sort(nums.begin(), nums.end(), [](pair<int, int>& a, pair<int, int>& b){
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        });

        for(auto [i, j] : nums){
            cout << j << " ";
        }

        cout << endl;
    }
}