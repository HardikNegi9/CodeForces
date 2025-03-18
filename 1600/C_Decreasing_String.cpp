#include<iostream>
#include<stack>
#include<vector>
#include<set>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int pos;
        cin >> pos;

        stack<char> stk;
        vector<int> v;
        set<char> st;

        for(char c : s){
            while(stk.size() && stk.top() > c){
                v.push_back(stk.top());
                stk.pop();
            }
            stk.push(c);
        }

        while(stk.size()){
            v.push_back(stk.top());
            stk.pop();
        }

        int n = s.size();
        int i = 0;

        while(n < pos){
            pos -= n;
            n--;
            st.insert(v[i]);
            i++;
        }

        for(char c : s){
            if(st.count(c)) continue;
            pos--;
            if(pos == 0) cout << c;
        }
    }
}