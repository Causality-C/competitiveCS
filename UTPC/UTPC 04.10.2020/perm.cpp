//Sample Template for .cpp solutions
#include<bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i = (a); (i)<(b); (i)++)
#define re(i,a) rep((i),0,a)
using namespace std;
typedef long long ll;
int N,Q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>Q;

    //Cycle # to individual # & distance within cycle
    map<int,pair<int,int>> mCyc; //pair<cycle#,#dist>

    int arr[N];
    bool visit[N];

    //Read in Graph
    re(i, N){
        cin>>arr[i];
        arr[i]--;
        visit[i] = 0;
    }
    int visited = 0;
    int cyc = 0;
    int idx = 0;
    //At most N cycles
    vector<int> v[N];
    while(visited< N){
        //Find next unvisited index
        while(visit[idx] != 0 && idx<N){
            idx++;
        }
        if(visit[idx] == 0 && idx<N){
            visited++;
            vector<int> thisCycle;
            visit[idx] = 1;
            int currIndex = idx;
            //Indexing starts at 0
            mCyc[idx] = make_pair(cyc, 0);
            thisCycle.push_back(currIndex);
            while(arr[currIndex] != idx){
                currIndex = arr[currIndex];
                mCyc[currIndex] = make_pair(cyc, thisCycle.size());
                thisCycle.push_back(currIndex);
                visit[currIndex] = 1;
                visited++;
            }
            v[cyc] = thisCycle;
            cyc++;
        }
    }
    
    //Query
    int f, t;
    while(Q-->0){
        cin>>f>>t;
        f--;
        cyc = mCyc[f].first;
        printf("%d\n",v[cyc][(mCyc[f].second + t)% v[cyc].size()]+1);
    }
}
