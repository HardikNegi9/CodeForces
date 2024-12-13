#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> nums(n);
        for(int i=0; i<n; i++){
            cin >> nums[i];
        }

        map<pair<int, int>, int> numMap;
        long long res = 0;
        for(int num : nums){
            long long X = (x - num % x) % x;
            long long Y = num % y;
            if(numMap.count({X, Y})){
                res += numMap[{X, Y}];
            }
            numMap[{num % x, num % y}]++;
        }

        cout << res << endl;
    }
}