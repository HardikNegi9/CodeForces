#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        map<long long, int> map;
        for(int i=0; i<n; i++){
            cin>>a[i];
            map[a[i]]++;
        }

        long long res = 0;

        for(auto [i, freq] : map){
            if(map.find(i - 1) != map.end()){
                int ele = min(freq, map[i-1]);
                int extra = freq - ele;
                res += extra;
            }else{
                res += freq;
            }
        }

        cout<<res<<endl;

    }
}