#include<iostream>
#include<set>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        bool flag = true;
        set<char> set;
        for(char c : s){
            set.insert(c);
        }
        int m = set.size();
        for(int i = 0; i < n; i++){
            if(s[i] != s[i % m]) flag = false;
        }

        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}