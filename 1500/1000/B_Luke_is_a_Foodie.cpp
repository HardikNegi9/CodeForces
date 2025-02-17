#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        long long x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        int res = 0;

        long long mn = a[0] - x;
        long long mx = x + a[0];

        for(int i = 1; i < n; i++){
            long long l = a[i] - x;
            long long r = x + a[i];

            pair<int, int> pr = {max(l, mn), min(mx, r)};
            if(pr.first > pr.second){
                res++;
                mn = l;
                mx = r;
            }else{
                mn = pr.first;
                mx = pr.second;
            }
        }
        cout<<res<<endl;
    }
}
