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
    //Check for Divisibility by Square Numbbers
    bool * squareDiv = new bool[10000000];
    for(int p = 2; p<= 999; p++ ){
        for(int j = p*p; j<10000000; j+= p*p){
            squareDiv[j] = true; 
        }
    }
    for (int p=2; p<10000000; p++) 
    { 
        if(primes[p] == false) 
        {  
            for (int i=p*2; i<=10000000; i += p) 
                primes[i] = true; 
        } 
    }
    
    re(i, T){
        //Read in value
        scanf("%d", &N);
        //Primes mean its imposible
        if(primes[N] == 0){
            printf("IMPOSSIBLE\n");
        }
        else{
            bool hasFactor = 0;
            if(squareDiv[N] == 0){
                printf("1\n");
            }
            else{
                for(int i = 2; i< sqrt(N); i++){
                //Is this a factor
                if(N%i == 0){
                    // printf("Primes[%d]: %d squareDiv[%d]: %d \n",i,primes[i],i,squareDiv[i]);
                    // printf("Primes[%d]: %d squareDiv[%d]: %d \n",N/i,primes[N/i],N/i,squareDiv[N/i]);
                    // printf("\n");
                    if(primes[i] && primes[N/i] && !squareDiv[i] && !squareDiv[N/i]){
                        hasFactor = 1;
                        break;
                         }
                    }
                }
                if(hasFactor){
                    printf("2\n");
                }
                else{
                    printf("IMPOSSIBLE\n");

                }
            }
        }
    }

}
