#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> seg(n);
    for(int i = 0; i < n; i++){
        cin >> seg[i].first.first >> seg[i].first.second;
        seg[i].second = i + 1;
    }

    sort(seg.begin(), seg.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
        if(a.first.first == b.first.first){
            return a.first.second > b.first.second;
        }
        return a.first.first < b.first.first;
    });

    for(int i = 0; i < n - 1; i++){
        if(seg[i].first.second >= seg[i + 1].first.second){
            cout << seg[i + 1].second << " " << seg[i].second << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;
}