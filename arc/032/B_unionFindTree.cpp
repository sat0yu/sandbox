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

int N,M;
int uf_parent[100001], uf_rank[100001];

int root(int a){
    if(uf_parent[a] == a){
        return a;
    }else{
        return ( uf_parent[a] = root(uf_parent[a]) );
    }
}

void unite(int a, int b){
    int root_a = root(a),
        root_b = root(b);
    if(uf_rank[root_a] > uf_rank[root_b]){
        uf_parent[root_b] = root_a;
    }else if(uf_rank[root_a] < uf_rank[root_b]){
        uf_parent[root_a] = root_b;
    }else{
        // choose root_a as a root of root_b since both nodes can be used
        uf_parent[root_a] = root_b;
        // increment the rank of the tree having node 'a' as its root
        uf_rank[root_a]++;
    }
}

bool isSameSet(int a, int b){
    return (root(a) == root(b)) ? true : false;
}

int main(int argc, char** argv){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        uf_parent[i] = i;
        uf_rank[i] = 0;
    }
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        unite(a,b);
    }
    int ret = 0;
    for(int i=1; i<=N; i++){
        // if a node is the root of it own tree
        if( root(i) == i ){
            ret++;
        }
    }
    cout << ret-1 << endl;

    return 0;

}
