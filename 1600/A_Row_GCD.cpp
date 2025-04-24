#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b){
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (long long i = 0; i < m; i++) {
        cin >> b[i];
    }

    long long g = 0;
    for (long long i = 1; i < n; i++) {
        g = gcd(g, abs(a[i] - a[0]));
    }

    for (long long i = 0; i < m; i++){
        long long val =  gcd(a[0] + b[i], g);
        cout << val << " ";
    }
}
