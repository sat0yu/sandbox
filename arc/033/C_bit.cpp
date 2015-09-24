#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<math.h>

#define _GLIBCXX_DEBUG

#define UINT unsigned int
#define ULL unsigned long long

#define MAX(x,y) ( (x)>(y) ? (x) : (y) )
#define MIN(x,y) ( (x)<(y) ? (x) : (y) )

using namespace std;

int N=2000001;
int BIT[2000001] = {0};

// int N=8+1;
// int BIT[8+1] = {0};

void add(int X){
    for(int x=X; x<=N; x += x & -x){
        BIT[x] += 1;
    }

    // for(int i=0; i<N; i++){ printf("%d ", BIT[i]); }
    // cout << endl;
}
void remove(int X){
    for(int x=X; x<=N; x += x & -x){
        BIT[x] -= 1;
    }

    // for(int i=0; i<N; i++){ printf("%d ", BIT[i]); }
    // cout << endl;
}
void search(int X){
    int k=1;
    for(; k<N; k<<=1){}
    k>>=1;

    int x=0;
    for(; k>0; k>>=1){
        // printf("X:%d > BIT[x:%d + k:%d]:%d\n", X, x, k, BIT[x+k]);
        if( (x + k <= N) and (X > BIT[x + k]) ){
            X -= BIT[x + k];
            x += k;
        }
    }

    // considering the case in which binary-search gets to a leaf,
    // 1 added to X; the 1 means the smallest range represented by k
    // cout << "searched: " << x+1 << endl;
    remove(x+1);

    cout << x+1 << endl;
}

int main(int argc, char** argv){
    int Q,T,X;
    cin >> Q;
    for(int i=0; i<Q; i++){
        cin >> T >> X;
        if(T==1){
            add(X);
        }else{
            search(X);
        }
    }
    return 0;
}
