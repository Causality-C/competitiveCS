//Sample Template for .cpp solutions
#include<bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i = (a); (i)<(b); (i)++)
#define re(i,a) rep((i),0,a)
using namespace std;
typedef long long ll;
int N, B, A;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    re(i, N){
        cin>>B>>A;
        int arr[B];
        re(j,B){
            cin>> arr[j];
        }
        sort(arr, arr+B);
        int sum = arr[0];
        int idx = 1;
        while(sum<=A && idx<=B){
            sum+=arr[idx];
            idx++;
        }
        cout<< "Case #"<< i+1<< ": "<<idx-1<<endl;
    }
}