#include <iostream>
using namespace std;

long long countFactor(long long n, int factor) {
    long long count = 0;
    while (n % factor == 0) {
        count++;
        n /= factor;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        long long n5 = countFactor(n, 5);
        long long n2 = countFactor(n, 2);
        
        int k = 1;
        if(n5 > n2){
            for(int i = 1; i <= n5 - n2 && k * 2 <= m ; i++){
                k *= 2;
            }
        }else{
            for(int i = 1; i <= n2 - n5 && k * 5 <= m ; i++){
                k *= 5;
            }
        }

        while(k * 10 <= m){
            k *= 10;
        }

        cout << (m / k) * k * n << endl;
    }
    return 0;
}