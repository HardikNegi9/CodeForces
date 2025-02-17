#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main() {
    int n;
    int k;
    cin >> n >> k;
    
    vector<double> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double size = n - k + 1;
    double res = 0.0;
    int multi = 1;
    double sum = 0.0;

    int l = 0;
    for(int r = 0; r < n; r++){
        sum += a[r];

        if(r - l + 1 == size){
            res += sum;
            sum -= a[l];
            l++;
        }
    }
    
    res /= size;

    cout << fixed << setprecision(10) << res << endl;
    
    return 0;
}