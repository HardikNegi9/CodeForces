#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

int main(){
    int n , q;
    cin >> n >> q;
    vector<int> nums(n);
    long long sum = 0;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        sum += nums[i];
    }

    int val = -1;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[nums[i]] = 0;
    }

    int all_rep = -1;
    int all_val = 0;

    for(int i = 0; i < q; i++){
        int op;
        cin >> op;

        if(op == 1){
            int idx, x;
            cin >> idx >> x;
            idx--;
            if(mp[idx] > all_rep){
                sum += (x - nums[idx]);
                nums[idx] = x;
            }else{
                sum += (x - all_val);
            }
            nums[idx] = x;
            cout << sum << endl;
            mp[idx] = i;
        }else{
            long long x;
            cin >> x;
            all_rep = i;
            all_val = x;
            sum = (n*x*1ll);
            cout << sum << endl;
        }
    }

}
