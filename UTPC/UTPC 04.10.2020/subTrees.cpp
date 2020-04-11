//Sample Template for .cpp solutions
#include<bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i = (a); (i)<(b); (i)++)
#define re(i,a) rep((i),0,a)
using namespace std;
typedef long long ll;
int N;
ll mod = 1000000007;
ll dfsSum(ll sumList[], vector<ll> list[], ll idx){
    if(list[idx].size() == 0){
        sumList[idx] = 1;
        return 1;
    }
    ll sum = 1;
    for(int i = 0; i< list[idx].size(); i++){
        sum*= (1+dfsSum(sumList, list, list[idx][i]))%mod;
        sum%=mod;
    }
    sumList[idx] = sum%mod;
    return sum%mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    // Adjacency List
    vector<ll> list[N];
    //Sum List
    ll sumList[N];
    ll V, E;
    re(i, N-1){
        cin>>V>>E;
        list[V-1].push_back(E-1);
    }
    ll subTrees = 0; 
    dfsSum(sumList, list, 0);
    for(ll i: sumList){
        subTrees+= i%mod;
        subTrees%= mod;
    }
    cout<<subTrees%mod<<endl;
}
