#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k, a, b;
        cin >> n >> k >> a >> b;
        vector<pair<long long, long long>> quord(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> quord[i].first >> quord[i].second;
        }
        long long res = abs(quord[a].first - quord[b].first) + abs(quord[a].second - quord[b].second);
        if(k == 0){
            cout << res << endl;
            continue;
        }

        long long min_dis_from_major = LLONG_MAX;
        long long min_dis_from_start_to_major = LLONG_MAX;

        for(int i = 1; i <= k; i++){
            long long dis = abs(quord[i].first - quord[b].first) + abs(quord[i].second - quord[b].second);
            min_dis_from_major = min(dis, min_dis_from_major);
            long long dis1 = abs(quord[i].first - quord[a].first) + abs(quord[i].second - quord[a].second);
            min_dis_from_start_to_major = min(dis1, min_dis_from_start_to_major);
        }

        cout << min(min_dis_from_major + min_dis_from_start_to_major, res) << endl;
    }
}