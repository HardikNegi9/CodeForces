#include<iostream>
using namespace std;

long long __gcd(long long a, long long b){
    if(b == 0){
        return a;
    }
    return __gcd(b, a%b);
}


int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n, x, y;
        cin >> n >> x >> y;
        long long lcm = (x*y)/__gcd(x, y);
        long long ele_notInBoth = n / lcm;
        long long ele_x = n / x - ele_notInBoth;
        long long ele_y = n / y - ele_notInBoth;
        long long rem = n - ele_x;
        long long X = (n*(n + 1))/2 - (rem*(rem+1))/2;
        long long Y = (ele_y*(ele_y + 1))/2;

        cout << X - Y << endl;
    }
}