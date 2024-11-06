#include<iostream>
#include<set>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<char> st;
        int res = 0;

        for(int i = 0; i < n; i++){
            if(st.count(s[i])){
                continue;
            }
            st.insert(s[i]);
            res += (n - i);
        }

        cout << res << endl;
    }
}