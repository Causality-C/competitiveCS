//plates.cpp
#include<bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i = (a); (i)<(b); (i)++)
#define re(i,a) rep((i),0,a)
using namespace std;
typedef long long ll;
int T,K,P,N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    re(c,T){
        cin>>K>>P>>N;
        int dp[K+1][N+1];
        int sum[K+1][P+1];
        for(int i = 0; i< K+1; i++){
            for(int j = 0; j<=N; j++){
                dp[i][j] = 0;
                if(j<=P){
                    sum[i][j] = 0;
                }
            }
        }
        //Read Input
        rep(j,1, K+1){
            rep(k,1, P+1){
                cin>>sum[j][k];
                if(k>1){
                    sum[j][k]+= sum[j][k-1];
                }
            }
        }
        rep(j,1, K+1){
            rep(k,1,N+1){
                for(int l = 0; l<= min(k,P); l++){
                    dp[j][k] = max(dp[j][k], sum[j][l] + dp[j-1][k-l]);
                }
            }
        }
       cout<< "Case #"<<c+1<<": "<<dp[K][N]<<endl;
    }
}