#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> gcds(n);
    gcds[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        gcds[i] = gcd(a[i], gcds[i + 1]);
    }

    vector<long long> final_gcds(n - 1);
    for (int i = 0; i < n - 1; i++) {
        final_gcds[i] = (a[i] * gcds[i + 1]) / gcd(a[i], gcds[i + 1]);
    }

    long long result = final_gcds[0];
    for (int i = 1; i < n - 1; i++) {
        result = gcd(result, final_gcds[i]);
    }

    cout << result << endl;
}
