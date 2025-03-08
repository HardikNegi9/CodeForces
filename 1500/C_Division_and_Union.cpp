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
        vector<pair<pair<int, int>, int>> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i].first.first >> arr[i].first.second;
            arr[i].second = i;
        }

        sort(arr.begin(), arr.end());

        vector<int> ans(n, -1);
        bool check = false;
        int maxR = arr[0].first.second;

        for(int i = 1; i < n; i++){
            if(arr[i].first.first > maxR){
                for(int j = 0; j < i; j++){
                    ans[arr[j].second] = 1;
                }
                for(int j = i; j < n; j++){
                    ans[arr[j].second] = 2;
                }
                check = true;
                break;
            }
            maxR = max(maxR, arr[i].first.second);
        }

        if(!check){
            cout << "-1" << endl;
        } else {
            for(int i = 0; i < n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}