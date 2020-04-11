//Sample Template for .cpp solutions
#include<bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i = (a); (i)<(b); (i)++)
#define re(i,a) rep((i),0,a)
using namespace std;
typedef long long ll;
int N, A, B, C;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>A>>B>>C;
    int minimum = 1000000;
    string ans;
    string temp;
    int arr[N][3];
    re(i, N){
        cin>>temp;
        for(int j = 0; j<3; j++){
            cin>>arr[i][j];
        }
        if(arr[i][0] * A + arr[i][1]*B  + arr[i][2] * C < minimum){
            ans = temp;
            minimum = arr[i][0] * A + arr[i][1]*B  + arr[i][2] * C;
        } 
        else if(arr[i][0] * A + arr[i][1]*B  + arr[i][2] * C == minimum && ans.compare(temp) > 0){
            ans = temp;
        }
    }
    printf("%s %d\n", ans.c_str(), minimum);

}
