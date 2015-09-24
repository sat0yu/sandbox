#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<string>
#include<math.h>

#define MAX(x,y) ( (x)>(y) ? (x) : (y) )
#define MIN(x,y) ( (x)<(y) ? (x) : (y) )

using namespace std;

// vector< vector<bool> > G(100001, vector<bool>(100001, false));
// vector< vector<int> > G(100001);
vector< set<int> > G(100001);
vector<bool> H(100001, false);
int N,M;

void dfs(int node){
    if(H[node]){
        return;
    }
    H[node] = true;
    for(int i=1; i<=N; i++){
        // if( G[node][i] and (!H[i]) ){
        // if( (!H[i]) and ( find( G[node].begin(), G[node].end(), i ) != G[node].end() ) ){
        if( (!H[i]) and ( G[node].find(i) != G[node].end() ) ){
            dfs(i);
        }
    }
    return;
}

int main(int argc, char** argv){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        // G[a][b] = G[b][a] = true;
        G[a].insert(b);
        G[b].insert(a);
    }

    // for(int i=0; i<=N; i++){
    //     for(int j=0; j<=N; j++){
    //         cout << G[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int count=0;
    for(int i=1; i<=N; i++){
        if(!H[i]){
            count++;
            dfs(i);
        }
    };
    cout << count - 1 << endl;

    return 0;

}
