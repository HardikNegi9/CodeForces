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
        vector<int> v(n);

        long long total = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            total += v[i];
        }

        sort(v.begin(), v.end());
        
        long long pre = 0;
        long long res = 0;
        int count = n;

        for(int i = 0; i < n; i++){
            pre += v[i];
            total -= v[i];
            count--;

            if(total <= pre){
                if(total < pre){
                    int diff = pre - total;
                    diff /= 2;

                    if(diff > 0){
                        count++;
                        pre -= diff;
                        total += diff;
                    }
                }
                res = count + pre;
                break;
            }
        }

        cout << res << endl;
    }
}