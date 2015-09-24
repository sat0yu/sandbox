#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<math.h>

#define UINT unsigned int
#define MAX(x,y) ( (x)>(y) ? (x) : (y) )
#define MIN(x,y) ( (x)<(y) ? (x) : (y) )

using namespace std;

int main(int argc, char** argv){
    int n,m,a,b;
    scanf("%d %d", &n, &m);
    vector<UINT> G(n+1, 0);
    // for(int i=1; i<=n; i++){
    //     G[i] |= (1<<i);
    // }

    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        G[a] |= (1<<b);
        G[b] |= (1<<a);
    }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << (bool)(G[i] & (1U<<j)) << " ";
    //     }
    //     cout << endl;
    // }

    for(int i=1; i<=n; i++){
        UINT temp=0;
        for(int j=1; j<=n; j++){
            if( G[i] & (1<<j) ){
                temp |= G[j];
            }
        }
        int ret=0;

        temp &= ~G[i];
        temp &= ~(1<<i);

        for(int j=1; j<=n; j++){
            if( temp & (1<<j) ){
                ret++;
            }
        }
        cout << ret << endl;
    }

    return 0;
}
