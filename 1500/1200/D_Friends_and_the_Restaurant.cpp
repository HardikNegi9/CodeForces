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
        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        vector<int> diff;
        for(int i = 0; i < n; i++){
            diff.push_back(b[i] - a[i]);
        }

        int left = 0;
        int right = n - 1;
        int res = 0;
        sort(diff.begin(), diff.end());
        while(left < right){
            long long valid = diff[left] + diff[right];
            if(valid >= 0){
                res++;
                left++;
                right--;
            }
            else{
                left++;
            }
        }

        cout << res << endl;
    }
}