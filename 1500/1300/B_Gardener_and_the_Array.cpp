#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> a(n);
        unordered_map<int, int> map;
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            long long val = 0;
            while(k--){
                int pos;
                cin >> pos;
                map[pos]++;
                a[i].push_back(pos);
            }
        }
        
        bool flag = true;
        for(int i = 0; i < n; i++){
            flag = true;
            for(int j : a[i]){
                if(map[j] == 1){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << "Yes" << endl;
                break;
            }
        }
        if(!flag){
            cout << "No" << endl;
        }
    }
}