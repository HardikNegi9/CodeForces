#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin >> v[i];
       
       int res = 0;
       vector<int> a;
       vector<int> b;

       a.push_back(v[0]);
       
        for(int i = 1; i < n; i++){
            if(a.size() > 0 && b.size() > 0){
                if(v[i] <= a.back() && v[i] <= b.back()){
                    if(a.back() < b.back()) a.push_back(v[i]);
                    else b.push_back(v[i]);
                }else if(v[i] <= a.back()){
                    a.push_back(v[i]);
                }else if(v[i] <= b.back()){
                    b.push_back(v[i]);
                }else{
                    if(a.back() < b.back()) a.push_back(v[i]);
                    else b.push_back(v[i]);
                    res++;
                }
            }else{
                if(a.back() < v[i]) b.push_back(v[i]);
                else{
                    a.push_back(v[i]);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}