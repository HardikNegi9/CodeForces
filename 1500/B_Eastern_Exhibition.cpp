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
        vector<int> x(n), y(n);

        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
        }

        if(n & 1){
            cout << 1 << endl;
        }else{    
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());

            long long dx = x[n/2] - x[n/2 - 1] + 1;
            long long dy = y[n/2] - y[n/2 - 1] + 1;

            cout << dx * dy << endl;
        }
    }
}