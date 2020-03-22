//workout.cpp
#include<bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i = (a); (i)<(b); (i)++)
#define re(i,a) rep((i),0,a)
using namespace std;
typedef long long ll;
int T,N,K;
//Helper function that calculates the minimum # of numbers inserted to get the min difference to a target value.
ll getAggregateSum(vector<ll> diff, double target){
    ll sum = 0;
    for(ll i: diff){
        sum+= max((ll)ceil(i/target)-1,0LL);
    }
    return sum;
}
//Binary Search
ll solve(vector<ll> diff, ll bound, ll target){
    ll ans =  bound;
    ll lo = 1;
    ll hi = bound;
    ll val;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        val = getAggregateSum(diff, mid);
        if(val> target){
            lo = mid+1;
        }
        else if(val<= target){
            hi = mid-1;
            ans = min(mid,ans);
        }
    }
    return ans;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    vector<ll> diffs;
    re(c,T){
        cin>>N>>K;
        ll arr[N];
        diffs.clear();
        ll upBound = -1;
        re(i,N){
            cin>>arr[i];
            if(i>0){
                diffs.push_back(arr[i]-arr[i-1]);
                if(diffs[i-1]>upBound){
                    upBound = diffs[i-1];
                }
            }
        }
        cout<<"Case #"<<c+1<<": "<<solve(diffs,upBound,K)<<endl;
    }
}