#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string str;
        cin >> str;

        int c = 0;
        int op = 0;

        for(char ch : str){
            if(ch == '(') c++;
            else{
                if(c > 0) c--;
                else op++;
            }
        }

        cout << op << endl;
    }
}