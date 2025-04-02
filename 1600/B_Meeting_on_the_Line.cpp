#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long double> p(n);
        vector<long double> t(n);

        for (int i = 0; i < n; i++) cin >> p[i];
        for (int j = 0; j < n; j++) cin >> t[j];

        long double mn = 1e18, mx = -1e18;
        for (int i = 0; i < n; i++) {
            mx = max(mx, p[i] + t[i]);
            mn = min(mn, p[i] - t[i]);
        }

        cout << fixed << setprecision(7) << (mx + mn) / 2.0 << endl;
    }
    return 0;
}