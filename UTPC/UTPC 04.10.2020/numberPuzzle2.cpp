//Sample Template for .cpp solutions
#include<bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i = (a); (i)<(b); (i)++)
#define re(i,a) rep((i),0,a)
using namespace std;
typedef long long ll;
int T,N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d", &T);
    //Check for Primes
    bool * primes = new bool[10000000];
    vector<int> v;
    for (int p=2; p<10000000; p++) 
    { 
        if(primes[p] == false) 
        {  
            v.push_back(p);
            for (int i=p*2; i<10000000; i += p) 
                primes[i] = true; 
        } 
    }
    re(i, T){
        //Read in value
        scanf("%d", &N);
        //Primes mean its imposible
        int maxPower = 0;
        int otherPower = 0;
        int currPrime = 0;
        while(currPrime < v.size() && N > 1){
            int currPower = 0;
            while(N%v[currPrime] == 0){
                currPower++;
                N/=v[currPrime];
            }
            if(currPower > maxPower){
                otherPower+=maxPower;
                maxPower = currPower;
            }
            else{
                otherPower+=currPower;
            }
            currPrime++;
        }
        if(maxPower > otherPower){
            printf("IMPOSSIBLE\n");
        }
        else{
            printf("%d\n", maxPower);
        }
        
    }

}
