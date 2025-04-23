#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

// Function to compute modular inverse using Fermat's Little Theorem
int modinv(int a, int mod) {
    int res = 1, b = mod - 2;
    while (b) {
        if (b & 1) res = (1LL * res * a) % mod;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    vector<int> v(1e4 + 1, 1);
    for (int i = 2; i <= 1e4; i++) {
        v[i] = (1LL * v[i - 1] * i) % mod;
    }

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> m(1e4 + 1, 0);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            m[x]++;
        }

        for (int i = 100; i >= 0; i--) {
            if (m[i] >= k) {
                int num = v[m[i]];
                int denom = (1LL * v[k] * v[m[i] - k]) % mod;
                int result = (1LL * num * modinv(denom, mod)) % mod;
                cout << result << endl;
                break;
            } else {
                k -= m[i];
            }
        }
    }

    return 0;
}
