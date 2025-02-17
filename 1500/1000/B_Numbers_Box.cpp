#include<iostream>
#include<vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int r, c;
        cin >> r >> c;
        int neg = 0;
        int pos = 0;
        int z = 0;
        vector<int> v;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int n;
                cin >> n;
                if(n < 0) neg++;
                else if(n > 0) pos++;
                else z++;
                if(n != 0)
                    v.push_back(abs(n));
            }
        }
        sort(v.begin(), v.end());

        if(neg % 2 == 0){
            cout << accumulate(v.begin(), v.end(), 0) << endl;
        }
        else{
            if(z == 0){
                cout << accumulate(v.begin() + 1, v.end(), 0 - v[0]) << endl;
            }
            else{
                cout << accumulate(v.begin(), v.end(), 0) << endl;
            }
        }
    }
}