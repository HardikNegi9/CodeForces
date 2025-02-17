#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> gaps(n+1);
        vector<int> pre(n+1, 0);
        vector<int> a(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            pre[i] = 0;
            gaps[i] = vector<int>();
        }

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; ++i) {
            gaps[a[i]].push_back(i - pre[a[i]] - 1);
            pre[a[i]] = i;
        }
        
        int mn = INT_MAX;
        for (int i = 1; i <= k; ++i) {
            gaps[i].push_back(n - pre[i]);
            sort(gaps[i].rbegin(), gaps[i].rend());
            int res = gaps[i][0] / 2;
            if (gaps[i].size() >= 2) {
                res = max(res, gaps[i][1]);
            }
            mn = min(mn, res);
        }
        cout << mn << endl;
    }
    return 0;
}