#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<vector<long long>> map(n + 1);
        for (int i = 0; i < n; i++) {
            map[a[i]].push_back(b[i]);
        }

        vector<long long> res(n + 1, 0);

        for (int i = 1; i <= n; i++) {  // For each unique value in `a`
            sort(map[i].rbegin(), map[i].rend());
            int m = map[i].size();

            for(int j = 1; j < m; j++) {
                map[i][j] += map[i][j - 1];
            }

            for (int j = 1; j <= m; j++) {
                int r = m % j;
                res[j] += map[i][m - r - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
