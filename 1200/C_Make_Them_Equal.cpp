#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin >> n;
        char c;
        cin >> c;
        string str;
        cin >> str;

        unordered_set<char> st;
        int idx = -1;
        for(int i = 0; i < n; i++){
            st.insert(str[i]);
            if(str[i] == c) idx = i;
        }

        if(st.size() == 1 && str[0] == c) cout << 0 << endl;
        else{
            if(str[n - 1] == c){
                cout << 1 << endl;
                cout << n << endl;
            }else{
                if(idx != -1){
                    int flag = true;
                    for(int i = idx + 1; i < n; i++){
                        if(str[i] != c && (i + 1) % (idx + 1) == 0) flag = false;
                    }

                    if(flag){
                        cout << 1 << endl << idx + 1 << endl; 
                    }else{
                        cout << 2 << endl << n - 1 << " " << n << endl;
                    }
                }else{
                    cout << 2 << endl;
                    cout << n - 1 << " " << n << endl;
                }
            }
        }
    }
}