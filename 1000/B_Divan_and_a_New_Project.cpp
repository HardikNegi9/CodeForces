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

        vector<pair<int, int>> a(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin() + 1, a.end(), greater<pair<int, int>>());

        long long time = 0;
        long long cur_c = 1;

        vector<long long> res(n + 1);

        for(int i = 1; i <= n; i++){
            time += a[i].first * (cur_c)*2ll;
            if(i & 1)
                res[a[i].second] = cur_c;
            else{
                res[a[i].second] = -cur_c;
                cur_c++;
            }
        }

        cout << time << endl;
        for(auto pos : res){
            cout << pos << " ";
        }
        cout << endl;

    }

}