#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<pair<int, int>> a;
        while(n--){
            int m;
            cin >> m;
            vector<int> nums(m);
            for(int i = 0; i < m; i++){
                cin >> nums[i];
            }
            sort(nums.begin(), nums.end());
            if(m == 1)
                a.push_back({nums[0], 0});
            else
                a.push_back({nums[0], nums[1]});
        }
        long long mn = 1e9;
        for(int i = 0; i < a.size(); i++){
            mn = min(a[i].first, (int)mn);
        }

        sort(a.begin(), a.end(), [](pair<int, int>& a, pair<int, int>& b){
            return a.second < b.second;
        });

        for(int i = 1; i < a.size(); i++){
            mn += a[i].second;
        }
        cout << mn << endl;
    }
}