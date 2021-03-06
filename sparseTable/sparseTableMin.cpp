/**
 * sparseTableMin.cpp
 * Used for range minimum queries in O(1) or O(logN) time
 * Creation of table takes O(NlogN) time.
 * Jeffrey Liu; 3/20/20
 */

#include <bits/stdc++.h>
#define MAX 1000
#define INF 1<<31 - 1
using namespace std;
int minTable[MAX][MAX];
int N,M;

//Helper Function that prints out the Sparse Table
void printTable(){
    for(int i = 0; i< M; i++){
        for(int j = 0; j< N; j++){
            cout<<minTable[i][j]<< " ";
        }
        cout<<endl;
    }
}

void genTable(int a[]){
    for(int i = 0; i< N; i++){
        minTable[0][i] = a[i];
    }
    for(int j = 1; j< M; j++){
        for(int i = 0; (i + (1<<j)-1) < N; i++){
            minTable[j][i] = min(minTable[j-1][i],minTable[j-1][i+(1<<(j-1))]);
        }
    }
}
//Performs a Minimum Query from ranges lo to hi inclusive in O(1) time.
int query(int lo, int hi){
    int row = log2(hi-lo+1);
    return min(minTable[row][lo],minTable[row][hi-(1<<row) +1]);
}

//Performs a Minimum Query from ranges lo to hi inclusive in O(logN) time where N is the length of the interval.
//Not optimal for Minimum Query but works for Associative but Non-Overlap friendly functions.
int queryCascade(int lo, int hi){
    int ans = INF;
    for(int i = log2(hi-lo+1); lo<=hi; i = log2(hi-lo+1)){
        ans = min(ans, minTable[i][lo]);
        lo+= 1<<i;
    }
    return ans;
}

int main(){
    //Table Creation
    int array[] =  {83, 11, 77, 82, 93, 35, 86, 92, 49, 21};
    N = sizeof(array)/sizeof(array[0]);
    M = floor(log2(N))+1;
    genTable(array);
    //printTable();

    //Query
    cout<<query(0,9)<< " "<< queryCascade(0,9)<< endl;
    cout<<query(4,7)<< " "<< queryCascade(4,7)<< endl;
    cout<<query(2,6)<< " "<< queryCascade(2,6)<< endl;
    cout<<query(0,1)<< " "<< queryCascade(0,1)<< endl;
}