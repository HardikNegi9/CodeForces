#include<iostream>
#include<set>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> v;
        for(int i = 0; i < n; i++){
            int ele;
            cin >> ele;
            v.insert(ele);
        }

        if(v.size() == n) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}