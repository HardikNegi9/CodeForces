#include<iostream>
using namespace std;

int solve(int l, int r){
    cout << "? " << l << " " << r << endl;
    
    int count = 0;
    for(int i = l; i <= r; i++){
        int x; cin >> x;
        if(l <= x && x <= r){
            count++;
        }
    }

    return count;
}



int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int left = 1, right = n;
        while(left < right){
            int mid = left + (right - left) / 2;
            
            int x = solve(left, mid);

            if(x & 1){
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << "! " << left << endl;
    }
}