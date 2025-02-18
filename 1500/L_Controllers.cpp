#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int pos = 0;
    int neg = 0;

    for(char c : s){
        if(c == '+'){
            pos++;
        }else{
            neg++;
        }
    }

    int q;
    cin >> q;
    while(q--){
        long long a, b;
        cin >> a >> b;

        if(a == b && neg == pos){
            cout << "YES";
        }else if(a == b && neg != pos){
            cout << "NO";
        }else{
            long long val  = b * (neg - pos);
            long long den = a - b;

            if(val % den != 0){
                cout << "NO";
            }else if(val / den >= -neg && val / den <= pos){
                cout << "YES";
            }else{
                cout << "NO";
            }
        }
        cout << endl;
    }
}