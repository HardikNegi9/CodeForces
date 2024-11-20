#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m = (n*(n-1))/2;

        vector<int> arr(m);
        for(int i = 0; i < m; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        int idx = m - 1;
        int cnt = 2;
        while(idx >= 0){
            cout << arr[idx] << " ";
            idx -= cnt;
            cnt++;
        }
        cnt = 1e9;
        cout << cnt << endl;

    }
}