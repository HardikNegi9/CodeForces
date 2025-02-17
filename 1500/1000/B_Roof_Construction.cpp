#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int temp = n - 1;
        int k = 0;
        while(1 << (k + 1) <=  n - 1){
            k++;
        }


        for(int i = 1; i < n; i++){
            if((1 << k) == i){
                cout << 0 << " ";
            }
            cout << i << " ";
        }

        cout << endl;
    }
}