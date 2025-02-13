#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

int main() {

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int> > v(n);
    	pbds A; // declaration

        for(int i = 0; i < n; i++){
            cin >> v[i].first >> v[i].second;
            A.insert(v[i].second);
        }
        
        long long res = 0;

        sort(v.begin(), v.end());

        for(int i = 0; i < n; i++){
            res += A.order_of_key(v[i].second);
            A.erase(v[i].second);
        }

        cout << res << endl;
        
    }

}