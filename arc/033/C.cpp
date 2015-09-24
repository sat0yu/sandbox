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

long numLeave = (1 << 22);
int counting_tree[1 << 23] = {0};

// int numLeave = 128;
// int counting_tree[2*128] = {0};

long idx2num(long idx){
    return (idx - numLeave + 1);
}
long num2idx(long num){
    return (num + numLeave - 1);
}

void add(long X){
    long idx = num2idx(X);
    while(idx > 0){
        // cout << idx << endl;
        counting_tree[idx]++;
        idx >>= 1;
    }
}

void remove(long X){
    long idx=1;
    while( idx2num(idx) < 1 ){
        // printf("idx2num(%ld);%ld, counting_tree[%ld];%d, X;%ld\n", idx, idx2num(idx), idx, counting_tree[idx], X);
        counting_tree[idx]--;

        // printf("counting_tree[idx << 1]:%d\n", counting_tree[idx << 1]);
        if( X > counting_tree[idx << 1] ){
            X -= counting_tree[idx << 1];
            idx = (idx << 1) +1;
        }else{
            idx = (idx << 1);
        }
    }
    counting_tree[idx]--;
    cout << idx2num(idx) << endl;
    return;
}

int main(int argc, char** argv){
    long Q,T,X;
    cin >> Q;
    for(int i=0; i<Q; i++){
        cin >> T >> X;
        if(T==1){
            add(X);
        }else{
            remove(X);
        }
    }
    return 0;
}
