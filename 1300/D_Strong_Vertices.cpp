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
        vector<int> a(n), b(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        vector<pair<int, int>> diff(n);
        for(int i = 0; i < n; i++){
            diff[i] = {a[i] - b[i], i};
        }

        sort(diff.begin(), diff.end(), greater<pair<int, int>>());

        vector<int> res;        
        res.push_back(diff[0].second);

        for(int i = 1; i < n; i++){
            if(diff[i].first != diff[i - 1].first){
                break;
            }
            res.push_back(diff[i].second);
        }

        sort(res.begin(), res.end());
        cout << res.size() << endl;
        for(int i = 0; i < res.size(); i++){
            cout << res[i] + 1 << " ";
        }
        cout << endl;

    }
}