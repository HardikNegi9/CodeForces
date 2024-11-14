#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        const int mod = 1e9 + 7;
        long long res = 2022;
        int x[] = {0,1};
        int y[] = {1,0};

        long long sum = 0;
        int r = 1, c = 1;
        for(long long i = 0; i < 2ll*(n - 1); i++){
            int j = i % 2;
            sum += r*c;

            r += x[j];
            c += y[j];
        }

        res = (res * sum) % mod;
        cout << res << endl;

    }
}