#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    vector<int> xors(3e5 + 1);
    xors[0] = 0;

    for(int i = 1; i < xors.size(); i++){
        xors[i] = xors[i - 1] ^ i;
    }

    while(t--){
        int a, b;
        cin >> a >> b;

        int x = xors[a - 1];

        if(x == b)
            cout << a << endl;
        else
            if((x^b) != a)
                cout << a + 1 << endl;
            else 
                cout << a + 2 << endl;
    }

}