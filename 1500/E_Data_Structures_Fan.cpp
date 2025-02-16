#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> nums[i];
        }

        string s;
        cin >> s;
        s = " " + s;

        vector<int> pre(n + 1, 0);
        int one = 0, zero = 0;

        for(int i = 1; i <= n; i++){
            if(s[i] == '1'){
                one ^= nums[i];
            }else{
                zero ^= nums[i];
            }

            pre[i] = pre[i - 1] ^ nums[i];
        }

        int q;
        cin >> q;

        while(q--){
            int op; cin >> op;

            if(op == 1){
                int l, r;
                cin >> l >> r;

                int val = pre[r] ^ pre[l - 1];

                one = one ^ val;
                zero = zero ^ val;
            }else{
                int g;
                cin >> g;

                cout << (g == 0 ? zero : one) << ' ';
            }
        }

        cout << endl;

    }
}