#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        long long n = str.size();

        long long count = 0;
        long long res = 0;
        long long st = 0;
        bool all_ones = true;

        for(int i = 0; i < n; i++){
            if(str[i] == '1') count++;
            else{
                if(all_ones){
                    st = count;
                }
                all_ones = false;
                res = max(res, count);
                count = 0;
                
            }
        }
        res = max(res, count + st);

        if(all_ones) cout << n * n << endl;
        else{
            int r = (res - 1) / 2;
            res = (res - r)*(r + 1);
            cout << res << endl;
        }
    }
}