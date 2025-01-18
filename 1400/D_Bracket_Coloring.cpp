#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;

        if(n & 1){
            cout << -1 << endl;
            continue;
        }

        stack<char> stk1;
        stack<char> stk2;
        vector<int> res(n, 1);

        bool pushed_in_stk1 = false;
        bool pushed_in_stk2 = false;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                if(stk2.size()){
                    stk2.pop();
                    res[i] = 2;
                }else{
                    stk1.push('(');
                    pushed_in_stk1 = true;
                }
            }else{
                if(stk1.size()){
                    stk1.pop();
                }else{
                    stk2.push(')');
                    pushed_in_stk2 = true;
                    res[i] = 2;
                }
            }
        }

        if(stk1.size() || stk2.size()){
            cout << -1 << endl;
            continue;
        }


        bool only_one = true;

        if(pushed_in_stk1 && pushed_in_stk2){
            only_one = false;
        }

        cout << (only_one ? 1 : 2) << endl;

        for(int i = 0; i < n; i++){
            cout << (only_one ? 1 : res[i]) << " ";
        }
        cout << endl;
    }
}