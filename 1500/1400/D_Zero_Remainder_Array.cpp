#include<iostream>
#include<map>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        map<int, long long> map;
        int zeros = 0;
        for(int i = 0; i < n; i++){
            int ele;
            cin >> ele;
            if(ele % k != 0){
                ele =  k - (ele % k);
                map[ele]++;
            }
        }
        
        if(map.size() == 0){
            cout << 0 << endl;
            continue;
        }

        long long res = 0;
        for(auto [ele, freq] : map){
            long long steps = ele + 1;
            steps += (freq - 1) * k;
            res = max(res, steps);
        }

        cout << res << endl;

    }
}