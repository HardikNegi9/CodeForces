#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 1001;

int main() {
    int t;
    cin >> t;

    vector<int> steps(MAX_N, MAX_N);
    steps[1] = 0;

    for (int i = 1; i < MAX_N; i++) {
        for (int j = 1; j <= i; j++) {
            int next = i + i / j;
            if (next < MAX_N) {
                steps[next] = min(steps[next], steps[i] + 1);
            }
        }
    }

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> b(n), c(n);

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }

        int max_steps = 0;
        for (int i = 0; i < n; i++) {
            max_steps += steps[b[i]];
        }
        k = min(k, max_steps);

        vector<int> dp(k + 1, 0);

        for (int i = 0; i < n; i++) {
            int cost = steps[b[i]];
            if (cost > k) continue;

            for (int j = k; j >= cost; j--) {
                dp[j] = max(dp[j], dp[j - cost] + c[i]);
            }
        }

        cout << *max_element(dp.begin(), dp.end()) << endl;
    }

    return 0;
}