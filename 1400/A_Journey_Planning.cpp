#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<pair<int, int>> pre(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pre[i] = {a[i] - i, a[i]};
    }

    sort(pre.begin(), pre.end());
    long long res = 0;
    long long curr_ress = pre[0].second;
    for(int i = 1; i < n; i++){
        if(pre[i].first == pre[i - 1].first){
            curr_ress += pre[i].second;
        }else{
            res = max(res, curr_ress);
            curr_ress = pre[i].second;
        }
    }
    res = max(res, curr_ress);
    cout << res << endl;

}
