#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        
        if(n > 2 && n&1){
            cout << "YES" << endl;
        }
        else{
            if(n&n-1)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
}