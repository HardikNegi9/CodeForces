#include<bits/stdc++.h>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


long long merge_sort(vector<int> & nums, int n, int low, int high){
    if(low >= high){
        return 0;
    }

    int mid = low + (high - low) / 2;
    long long res = merge_sort(nums, n, low, mid) + merge_sort(nums, n, mid + 1, high);

    vector<int> temp(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    while(i <= mid && j <= high){
        if(nums[i] <= nums[j]){
            temp[k++] = nums[i++];
        }else{
            res += mid - i + 1;
            temp[k++] = nums[j++];
        }
    }

    while(i <= mid){
        temp[k++] = nums[i++];
    }

    while(j <= high){
        temp[k++] = nums[j++];
    }

    for(int i = low; i <= high; i++){
        nums[i] = temp[i - low];
    }

    return res;
}


int main() {

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int> > v(n);
    	// pbds A; // declaration

        for(int i = 0; i < n; i++){
            cin >> v[i].first >> v[i].second;
            // A.insert(v[i].second);
        }
        
        // long long res = 0;

        sort(v.begin(), v.end()); // common in both

        // for(int i = 0; i < n; i++){
        //     res += A.order_of_key(v[i].second);
        //     A.erase(v[i].second);
        // }

        // cout << res << endl;

        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            nums[i] = v[i].second;
        }

        cout << merge_sort(nums, n, 0, n - 1) << endl;   
        
    }

}