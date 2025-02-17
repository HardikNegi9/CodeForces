#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<int> vec(n);
        int neg = 0, pos = 0;
        for(int i = 0; i < n; i++){
            cin >> vec[i];
            if(vec[i] <= 0) neg++;
            else pos++;
            vec[i] = abs(vec[i]);
        }
        sort(vec.begin(), vec.end());
        if(neg == 0 || neg % 2 == 0){
            cout << accumulate(vec.begin(), vec.end(), 0ll) << endl;
        }else{
            cout << accumulate(vec.begin(), vec.end(), 0ll) - 2 * vec[0] << endl;
        }
    }
}