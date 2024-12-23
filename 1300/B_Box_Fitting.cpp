#include<iostream>
#include<set>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, w;
        cin >> n >> w;
        int res = 1;
        multiset<long long> st;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            st.insert(x);
        }

        long long width = w;
        while(!st.empty()){
            auto it = st.upper_bound(width);
            if(it == st.begin()){
                res++;
                width = w;
            }else{
                it--;
                width -= *it;
                st.erase(it);
            }
        }

        cout << res << endl;
    }
}