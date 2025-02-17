#include<iostream>
#include<vector>
#include<map>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> map;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        int count = 1;

        int i = n - 2;
        int ele = a[n-1];
        int res = 0;
        while(i >= 0){
            if(a[i] == ele){
                count++;
                i--;
            }
            else{
                res++;
                i -= count;
                count *= 2;
            }
        }

        cout << res << endl;



    }
}