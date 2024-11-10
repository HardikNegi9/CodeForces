#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        int left = 0;
        int right = n - 1;

        while(left < n && a[left] == b[left]){
            left++;
        }
        while(right >= 0 && a[right] == b[right]){
            right--;
        }
        while(right < n - 1 && b[right] <= b[right + 1]){
            right++;
        }
        while(left > 0 && b[left] >= b[left - 1]){
            left--;
        }
        cout << left + 1 << " " << right + 1 << endl;
    }
}