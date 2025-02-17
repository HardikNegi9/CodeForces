#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<long long> a(n + 1), b(n + 1);
        vector<long long> pre(n + 1, 0);

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        for(int i = 1; i <= n; i++){
            cin >> b[i];
        }
        
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + b[i];
        }


        vector<long long> ended(n + 1, 0);
        vector<long long> rem(n + 1, 0);

        for(int i = 1; i <= n; i++){
            long long val = a[i] + pre[i - 1];

            int pos = upper_bound(pre.begin(), pre.end(), val) - pre.begin();

            if(pos <= n){
                ended[pos]++;
                rem[pos] += a[i] - (pre[pos - 1] - pre[i - 1]);
            }
        }

        for(int i = 1; i <= n; i++){
            ended[i] += ended[i - 1];
        }

        for(int i = 1; i <= n; i++){
            long long res = (i - ended[i])*b[i] + rem[i];
            cout << res << " ";
        }

        cout << endl;

    }
}