#include<iostream>
#include<vector>
using namespace std;
 

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int ans = 0;
        int ap = n, as = 0;
        for(int i = 0, l = -1; i <= n; i++) {
            if (i == n || a[i] == 0) {
                int cnt = 0;
                bool neg = false;
                int left = -1, right = -1;
                int cl = 0, cr = 0;
                for (int j = l+1; j < i; j++) {
                    neg ^= a[j] < 0;
                    if (a[j] < 0) {
                        right = j;
                        cr = 0;
                    }
     
                    if (abs(a[j]) == 2) {
                        cnt++, cr++;
                        if (left == -1) cl++;
                    }
     
                    if (a[j] < 0 && left == -1) {
                        left = j;
                    }
                }
                if (neg) {
                    if (cnt - cl > cnt - cr) {
                        right = i;
                        cnt -= cl;
                    } else {
                        left = l;
                        cnt -= cr;
                    }
                } else {
                    left = l, right = i;
                }
                if (ans < cnt) {
                    ans = cnt;
                    ap = left + 1, as = n - right;
                }
     
                l = i;
            }
        }
        cout << ap << ' ' << as << endl;
    }
}