#include <bits/stdc++.h>
using namespace std;

int calc_and(int l, int r, vector<int>& a, vector<vector<int>>& pre) {
    int result = 0;
    for (int i = 0; i < 30; i++) {
        if ((a[l] >> i) & 1 && pre[r][i] - (l != 0 ? pre[l-1][i] : 0) == r - l + 1) {
            result += 1 << i;
        }
    }
    return result;
}

int binary_search(int l, int k, vector<int>& a, vector<vector<int>>& pre) {
    int left = l;
    int right = a.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (calc_and(l, mid, a, pre) >= k) {
            result = mid + 1;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<vector<int>> pre(n, vector<int>(30, 0));
    for (int i = 0; i < 30; i++) {
        pre[0][i] = (a[0] >> i) & 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            pre[i][j] = pre[i-1][j] + ((a[i] >> j) & 1);
        }
    }
    
    int q;
    cin >> q;
    while (q--) {
        int l, k;
        cin >> l >> k;
        l--;
        cout << binary_search(l, k, a, pre) << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}