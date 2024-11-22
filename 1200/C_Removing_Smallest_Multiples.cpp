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
        set<int> st;
        int res = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                st.insert(i + 1);
            }
        }

        while(!st.empty()){
            int x = *st.begin();
            int ele = x;
            for(int i = 1; i <= n/x; i++){
                if(st.count(x * i)){
                    st.erase(x * i);
                    res += ele;
                }else break;
            }
        }

        cout << res << endl;
    }
}