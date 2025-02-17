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
        vector<pair<int,int>> mx1, mx2, mx3;

        auto vals = [&] () -> vector<pair<int, int>> {
            vector<pair<int, int>> arr;
            for(int i=0; i<n; i++){
                int val;
                cin >> val;
                arr.push_back({val, i});
            }
            
            sort(arr.begin(), arr.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
                return a.first > b.first;
            });
            
            return vector<pair<int,int>>(arr.begin(), arr.begin() + 3);
        };

        mx1 = vals();
        mx2 = vals();
        mx3 = vals();

        int res = 0;
        for(int i = 0; i < mx1.size(); i++){
            for(int j = 0; j < mx2.size(); j++){
                for(int k = 0; k < mx3.size(); k++){
                    if(mx1[i].second != mx2[j].second && 
                       mx2[j].second != mx3[k].second && 
                       mx1[i].second != mx3[k].second){
                        res = max(res, mx1[i].first + mx2[j].first + mx3[k].first);
                    }
                }
            }
        }

        cout << res << endl;
    }
    return 0;
}