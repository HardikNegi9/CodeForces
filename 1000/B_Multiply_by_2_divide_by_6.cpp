#include<iostream>
using namespace std;


int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int count_2 = 0;
        int count_3 = 0;

        while(n % 2 == 0){
            n /= 2;
            count_2++;
        }
        while(n % 3 == 0){
            n /= 3;
            count_3++;
        }

        if(n != 1 || count_2 > count_3){
            cout << -1 << endl;
        }
        else{
            cout << count_3 + (count_3 - count_2) << endl;
        }
    }
}