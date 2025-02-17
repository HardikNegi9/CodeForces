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
        vector<int> pos(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        for(int i = 1;i <= n; i++){
            pos[i - 1] = i;
        }

        bool flag = true;
        int i = 0;

        while(i < n){
            int ele = a[i];
            int left = i;
            int right = i;

            while(right < n && a[right] == ele) right++;

            if(left == right - 1){
                flag = false;
                break;
            }

            rotate(pos.begin()+left, pos.begin()+left+1, pos.begin()+right);
            i = right;
        }
        if(flag){
            for(int i = 0; i < n; i++){
                cout << pos[i] << " ";
            }
        }
        else{
            cout << -1 << endl;
        }
        cout << endl;
    }
}