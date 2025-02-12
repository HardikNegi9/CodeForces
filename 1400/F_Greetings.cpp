#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
   int n;
   cin >> n;

   priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
   FOR(i,0,n){
       int x, y;
       cin >> x >> y;
       pq.push({x, 0, y});
       pq.push({y, 1, x});
   }

   int ans = 0;
   set<long long> st;

   while(!pq.empty()){
       int x = pq.top()[0];
       int y = pq.top()[1];
       int z = pq.top()[2];
       pq.pop();
       
       if(y == 0){
           st.insert(x);
       } else {
           st.erase(st.find(z));

           int count = distance(st.begin(), st.lower_bound(z));
           ans += count;
       }
   }
   cout << ans << '\n';
}