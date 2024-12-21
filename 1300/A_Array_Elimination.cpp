#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(33, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];

            for(int j = 0; j < 33; j++){
                if(a[i] & (1 << j)){
                    b[j]++;
                }
            }
        }

        int res = 0;
        for(int i = 1; i <= n; i++){
            bool flag = true;
            for(int j = 0; j < 33; j++){
                if(b[j] % i != 0){
                    flag = false;
                    break;
                }
            }

            if(flag){
                cout << i << " ";
            }
        }

        cout << endl;

    }
}