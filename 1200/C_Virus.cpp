#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for(int i = 0; i < m; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        vector<int> diff;
        for(int i = 1; i < m; i++){
            diff.push_back(a[i] - a[i - 1] - 1);
        }

        diff.push_back(n - a[m - 1] + a[0] - 1);
        sort(diff.rbegin(), diff.rend());

        int res = 0;
        int day = 0;
        for(int d : diff){
            int curr = d;
            curr -= (day*2);
            if(curr <= 0) break;
            res += (curr - 1);
            if(curr == 1) res++;
            day += 2;
        }

        cout << n - res << endl;
    }
}