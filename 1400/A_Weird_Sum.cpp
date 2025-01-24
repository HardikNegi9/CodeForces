#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    map<int, vector<pair<long long, long long>>> map;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            map[x].push_back({i, j});
        }
    }

    long long res = 0;
    
    for(auto [x, nums] : map){
        int size = nums.size();
        if(size < 2) continue;
        long long sumi = 0;
        sort(nums.begin(), nums.end());
        for(auto [i, j] : nums){
            sumi += i;
        }
        for(int i = 0; i < size; i++){
            res += abs(sumi - nums[i].first * (size - i));
            sumi -= nums[i].first;
        }
        long long sumj = 0;
        sort(nums.begin(), nums.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        });
        for(auto [i, j] : nums){
            sumj += j;
        }
        for(int i = 0; i < size; i++){
            res += abs(sumj - nums[i].second * (size - i));
            sumj -= nums[i].second;
        }
    }

    cout << res << endl;
}