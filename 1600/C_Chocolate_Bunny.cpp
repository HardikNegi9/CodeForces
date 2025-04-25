#include<iostream>
#include<vector>
using namespace std;

int interact(int a, int b){
    cout << "? " << a + 1 << " " << b + 1 << endl << endl;
    int x;
    cin >> x;
    return x;
}


int main(){
    int n;
    cin >> n;
    vector<int> res(n);
    int idx = 0;
    for(int i = 1; i < n; i++){
        int x = interact(idx, i);
        int y = interact(i, idx);

        if(x < y){
            res[i] = y;
        }else{
            res[idx] = x;
            idx = i;
        }
    }
    res[idx] = n;
    cout << "! ";
    for(int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
}