#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            l[i]--;
            r[i]--;
        }

        int q;
        cin >> q;
        vector<int> qu(q);
        for (int i = 0; i < q; i++) {
            cin >> qu[i];
            qu[i]--;
        }

        int left = 0, right = q - 1;
        int res = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            vector<int> nums(m, 0);

            for (int i = 0; i <= mid; i++) {
                nums[qu[i]] = 1;
            }

            for (int i = 1; i < m; i++) {
                nums[i] += nums[i - 1];
            }

            bool flag = false;

            for (int i = 0; i < n; i++) {
                int ones = nums[r[i]] - (l[i] == 0 ? 0 : nums[l[i] - 1]);
                int zeros = (r[i] - l[i] + 1) - ones;
                if (ones > zeros) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (res == -1) {
            cout << -1 << endl;
        } else {
            cout << res + 1 << endl;
        }
    }

    return 0;
}