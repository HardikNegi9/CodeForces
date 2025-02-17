#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<int> ans;

        ans.push_back(a[0]);
        for(int i = 1; i < n - 1; i++){
            if(a[i - 1] < a[i] && a[i] < a[i + 1]) continue;
            if(a[i - 1] > a[i] && a[i] > a[i + 1]) continue;
            ans.push_back(a[i]); 
        }
        ans.push_back(a[n - 1]);

        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }
}