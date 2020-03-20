/**
 * sparseTableProduct.cpp
 * Used for range product queries O(logN) time
 * Creation of table takes O(NlogN) time.
 * Jeffrey Liu; 3/20/20
 */

#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
int multTable[MAX][MAX];
int N,M;

//Helper Function that prints out the Sparse Table
void printTable(){
    for(int i = 0; i< M; i++){
        for(int j = 0; j< N; j++){
            cout<<multTable[i][j]<< " ";
        }
        cout<<endl;
    }
}

void genTable(int a[]){
    for(int i = 0; i< N; i++){
        multTable[0][i] = a[i];
    }
    for(int j = 1; j< M; j++){
        for(int i = 0; (i + (1<<j)-1) < N; i++){
            multTable[j][i] = multTable[j-1][i]* multTable[j-1][i+(1<<(j-1))];
        }
    }
}

//Performs a Product Query from ranges lo to hi inclusive in O(logN) time where N is the length of the interval.
int queryCascade(int lo, int hi){
    int ans = 1;
    for(int i = log2(hi-lo+1); lo<=hi; i = log2(hi-lo+1)){
        ans *= multTable[i][lo];
        lo+= 1<<i;
    }
    return ans;
}

int main(){
    //Table Creation
    int array[] =  {43, -44, 98, -73, 40, 69, 58, -43, 47, 92};
    N = sizeof(array)/sizeof(array[0]);
    M = floor(log2(N))+1;
    genTable(array);
    //printTable();

    //Query
    cout<<queryCascade(0,9)<< endl;
    cout<<queryCascade(4,7)<< endl;
    cout<<queryCascade(2,6)<< endl;
    cout<<queryCascade(0,1)<< endl;
}