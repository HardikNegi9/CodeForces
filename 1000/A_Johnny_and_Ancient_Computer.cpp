#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;

        int count_a = 0;
        int count_b = 0;

        while(a % 2 == 0){
            a /= 2;
            count_a++;
        }

        while(b % 2 == 0){
            b /= 2;
            count_b++;
        }

        if(a != b){
            cout << -1 << endl;
        }else{
            int diff = abs(count_a - count_b);
            cout << (diff + 2) / 3 << endl;
        }
    }
}