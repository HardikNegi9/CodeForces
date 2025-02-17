#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int res = 0;
    sort(a.begin(), a.end());
    int i = -1, j = n - 1;
    long long curr = a[j];

    while(i < j){
        int max_val = a[j];
        if(curr <= d){
            i++;
            curr += max_val;
        }else{
            res++;
            j--;
            if(j >= 0){
                curr = a[j];
            }
        }
    }
    cout << res << endl;

}