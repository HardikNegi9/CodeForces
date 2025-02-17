#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        string s, t;
        cin >> n >> s >> t;
        vector<pair<int, int>> v;
        int count = 0;
        int j = 0;
        for(int i=0; i<s.size(); i++){
            s[i] == '1' ? count++ : count--;
            if(count == 0){
                v.push_back({j, i});
                j = i+1;
            }
        }

        for(auto [start, end] : v){
            if(s[start] == t[start]){
                continue;
            } else {
                for(int i=start; i<=end; i++){
                    s[i] = (s[i] == '1' ? '0' : '1');
                }
            }
        }

        bool flag = true;
        for(int i=0; i<n; i++){
            if(s[i] != t[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}