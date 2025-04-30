#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<bool> used_mod(m, false);
    bool has_duplicate_mod = false;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (used_mod[a[i] % m]) {
            has_duplicate_mod = true;
        }
        used_mod[a[i] % m] = true;
    }

    if (has_duplicate_mod) {
        cout << 0 << endl;
        return 0;
    }

    long long res = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            res = (res * (abs(a[i] - a[j]) % m)) % m;
        }
    }

    cout << res << endl;
    return 0;
}
