#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        int sum = 0;
        int c_2 = 0;
        int c_3 = 0;

        for(char c : s){
            sum += c - '0';
            if(c == '2'){
                c_2++;
            }
            if(c == '3'){
                c_3++;
            }
        }

        int rem = sum % 9;

        bool flag = (rem == 0);
        for(int i = 0; i <= c_2; i++){
            for(int j = 0; j <= c_3; j++){
                int temp = 2*i + 6*j;
                temp = (rem + temp) % 9;
                if(temp == 0){
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }

        if(flag){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }


    }
}