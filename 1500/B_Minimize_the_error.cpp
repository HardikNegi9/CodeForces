#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        pq.push(abs(a[i] - b[i]));
    }


    while(k1 + k2 > 0){
        int top = pq.top();
        pq.pop();
        pq.push(abs(top - 1));
        if(k1) k1--;
        else k2--;
    }

    long long ans = 0;
    while(!pq.empty()){
        ans += 1LL * pq.top() * pq.top();
        pq.pop();
    }

    cout << ans << endl;

    
    
}