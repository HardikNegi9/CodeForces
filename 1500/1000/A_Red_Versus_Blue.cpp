#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, r, b;
        cin >> n >> r >> b;

        string s = "";

        int max_r = r / (b + 1);
        int remr = r % (b + 1);

        while(r || b){
            for(int i = 0; i < max_r && r > 0; i++){
                cout << "R";
                r--;
            }
            if(remr > 0 && r > 0){
                cout << "R";
                remr--;
                r--;
            }
            if(b > 0){
                cout << "B";
                b--;
            }
        }
        cout << endl;
    }
}