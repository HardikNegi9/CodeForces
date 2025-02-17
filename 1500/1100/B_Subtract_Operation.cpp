#include<iostream>
#include<vector>
#include<map>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        map<int, int> map; 
        for(int i=0; i<n; i++){
            cin >> a[i];
            map[a[i]]++;
        }

        bool flag = true;
        for(int i : a){
            map[i]--;
            if(map[i - k] || map[i + k]){
                flag = false;
                cout << "YES" << endl;
                break;
            }
        }


        if(flag){
            cout << "NO" << endl;
        }
    }
}