#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> v(n + 1, 0);
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            v[max(a, b)] = max(v[max(a, b)], min(a, b));
        }

        long long res = 0;
        int len = 1;
        for(int i = 1; i <= n; i++){
            len = min(i - v[i], len);
            res += len;
            len++;
        }

        cout << res << endl;

    }
}