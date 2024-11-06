#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int res = 0;
        vector<int> nums(n);
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        unordered_set<int> st;
//pass 1
        for(int i = 0; i < n; i++){
            cin >> nums[i];
            st.insert(nums[i]);
        }

        int count = 1;
        map1[nums[0]] = 1;
        for(int i = 1; i < n; i++){
            if(nums[i - 1] == nums[i]){
                count++;
            }
            else{
                count = 1;
            }
            map1[nums[i]] = max(count, map1[nums[i]]);
        }

// pass 2
        for(int i = 0; i < n; i++){
            cin >> nums[i];
            st.insert(nums[i]);
        }

        count = 1;
        map2[nums[0]] = 1;
        for(int i = 1; i < n; i++){
            if(nums[i - 1] == nums[i]){
                count++;
            }
            else{
                count = 1;
            }
            map2[nums[i]] = max(count, map2[nums[i]]);
        }
        
        for(int i : st){
            res = max(res, map1[i] + map2[i]);
        }

        cout << res << endl;
    }
}