#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int i = 1; i < n; i++){
        if(s[i] < s[i - 1]){
            cout << "YES" << endl;
            cout << i << " " << i + 1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}