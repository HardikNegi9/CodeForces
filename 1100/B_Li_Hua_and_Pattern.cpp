#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        int count = 0;
        vector<vector<int>> arr(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] != arr[n - 1 - i][n - 1 - j]){
                    count++;
                }
            }
        }
        count = count >> 1;

        if(count > q) cout << "NO" << endl;
        else{
            q -= count;
            if(n&1) cout << "YES" << endl;
            else if(q&1) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
}