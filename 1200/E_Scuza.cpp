#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<long long> nums(n);
        vector<long long> ques(q);

        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        for(int i = 0; i < q; i++){
            cin >> ques[i];
        }

        vector<long long> pre(n + 1);
        pre[0] = 0;
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + nums[i - 1];
        }

        vector<long long> mx(n);
        mx[0] = nums[0];
        for(int i = 1; i < n; i++){
            mx[i] = max(mx[i - 1], nums[i]);
        }

        
        for(int q : ques){
            int pos = upper_bound(mx.begin(), mx.end(), q) - mx.begin();
            cout << pre[pos] << " ";
        }

        cout << endl;

    }
}