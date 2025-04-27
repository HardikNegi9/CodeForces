#include<iostream>
#include<vector>
using namespace std;

int main() {
    long long t; 
    cin >> t;
    while (t--) {
        long long n, k, z; 
        cin >> n >> k >> z;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) cin >> a[i];

        long long result = 0;
        long long current_sum = 0;
        long long max_pair = 0;

        for (long long i = 0; i <= k; i++) {
            current_sum += a[i];
            if (i < n - 1) {
                max_pair = max(max_pair, a[i] + a[i + 1]);
            }

            long long moves_left = k - i;
            long long max_left_moves = min(z, moves_left / 2);

            long long total = current_sum + max_pair * max_left_moves;
            result = max(result, total);
        }

        cout << result << endl;
    }
    return 0;
}
