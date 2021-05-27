#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod (long long)(1e9+7)
#define endl "\n"
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define cerr if(false)cerr  //comment this to stop debugging
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
 
void solve(){
    
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,int>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[a[i]]++;
    }
    map<int,int>m1;
    for(auto i : m){
        m1[i.second]++;
    }
    int res=n;
    int left = 0, right = n , rightCount = m.size();
    for(auto i : m1){
        res= min(res,left+right-(rightCount*i.first));
        left += i.first*i.second;
        right -= i.first*i.second;
        rightCount -= i.second;
    }

    cout<<res<<endl;

}
 
int32_t main(){
 
	ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
	return 0;
}