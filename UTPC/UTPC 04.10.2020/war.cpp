//war.cpp
#include<bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i = (a); (i)<(b); (i)++)
#define re(i,a) rep((i),0,a)
using namespace std;
typedef long long ll;
int N;
char SUIT;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>SUIT;
    //Both teams start with no wins
    int a = 0;
    int b = 0;
    map<char, int> cPres;
    //Special Cards
    cPres['T'] = 10;
    cPres['J'] = 11;
    cPres['Q'] = 12;
    cPres['K'] = 13;
    cPres['A'] = 14;

    string C1;
    string C2;
    re(i, N){
        cin>>C1>>C2;
        //Aditya has Trump
        if(C1[1] == SUIT && C2[1] != SUIT){
            a++;
        }
        //Brian has Trump
        else if(C1[1] != SUIT && C2[1] == SUIT){
            b++;
        }
            
        //Both have same Suit
        else if(C1[1] == C2[1]){
            int rank1;
            int rank2;
            //Assigning Ranks
            if(C1[0] > '9'){
                rank1 = cPres[C1[0]];
            }
            else{
                rank1 = C1[0] - '0';
            }

            if(C2[0] > '9'){
                rank2 = cPres[C2[0]];
            }
            else{
                rank2 = C2[0] - '0';
            }

            if(rank1 == rank2){
                a++;
            }
            else{
                rank1>rank2 ? a++ : b++;
            }
        }
        else{
            b++;
        }
    }
    if(a== b){
        printf("TIE %d\n", a);
    }
    else if(a>b){
        printf("ADITYA %d\n", a);
    }
    else{
        printf("Brian %d\n", b);
    }
}
