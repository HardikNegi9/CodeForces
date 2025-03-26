#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 998244353;

long long modPower(long long base, long long exponent, long long mod) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return result;
}

long long modInverse(long long x, long long mod) {
    return modPower(x, mod - 2, mod);
}

long long nCr(int n, int r, long long mod) {
    if (r > n) return 0;
    long long res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i) % mod;
        res = res * modInverse(i + 1, mod) % mod;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    if (n % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> v(n);
    for (auto &i : v) {
        cin >> i;
    }

    long long res = nCr(n / 3, n / 6, mod);
    vector<int> temp;

    for (int i = 0; i < n; i++) {
        temp.push_back(v[i]);
        if ((i + 1) % 3 == 0) {
            sort(temp.begin(), temp.end());
            if (temp.back() == temp.front()) {
                res = (res * 3) % mod;
            } else if (temp[0] == temp[1] && temp[2] > temp[0]) {
                res = (res * 2) % mod;
            }
            temp.clear();
        }
    }

    cout << res << endl;
    return 0;
}