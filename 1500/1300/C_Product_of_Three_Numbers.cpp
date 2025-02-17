#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool found = false;
        for(int i = 2; i * i * i <= n; i++){
            if(n % i == 0){
                int n1 = n / i;
                for(int j = i + 1; j * j <= n1; j++){
                    if(n1 % j == 0){
                        int n2 = n1 / j;
                        if(n2 != i && n2 != j && n2 != 1){
                            cout << "YES" << endl;
                            cout << i << " " << j << " " << n2 << endl;
                            found = true;
                            break;
                        }
                    }
                }
                if(found) break;
            }
        }
        if(!found) cout << "NO" << endl;
    }
}