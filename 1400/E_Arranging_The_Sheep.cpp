#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string v;
        cin >> v;
        
        int cnt = 0;
        for(int i = 0; i < n; ++i)
            if(v[i] == '*')
                ++cnt;
        cnt = (cnt + 1) / 2;
        
        int s = 0, mid_pos = 0;
        for(int i = 0; i < n; ++i)
            if(v[i] == '*') {
                ++s;
                if(s == cnt) {
                    mid_pos = i;
                    break;
                }
            }
        
        long long res = 0;
        cnt = 0;
        
        for(int j = mid_pos - 1; j >= 0; --j) {
            if(v[j] == '.')
                ++cnt;
            else
                res += cnt;
        }
        
        cnt = 0;
        for(int j = mid_pos + 1; j < n; ++j)
            if(v[j] == '.')
                ++cnt;
            else
                res += cnt;
        
        cout << res << endl;
    }
    return 0;
}