#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int ele1 = 0;
        int ele2 = -1;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[ele1] != arr[i]) ele2 = i;
        }

        if(ele2 == -1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
            for(int i = 1; i < n; i++){
                if(arr[i] != arr[ele1]){
                    cout << ele1 + 1 << " " << i + 1 << endl;
                }else{
                    cout << ele2 + 1 << " " << i + 1 << endl;
                }
            }
        }
    }
}