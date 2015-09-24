#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<math.h>

#define MAX(x,y) ( (x)>(y) ? (x) : (y) )
#define MIN(x,y) ( (x)<(y) ? (x) : (y) )

using namespace std;

// DFSで渡すのが面倒なのでグローバルで用意
int N;
// 350*(350+1)/2 = 61425
// スタック領域だと心配なのでヒープで確保
vector<int> T(70000);
vector<int> M(70000);

int dfs(int top, int left){
    int pos = top*(top-1)/2+left;
    // 最下段の場合はそのまま返す
    if(top == N){
        return M[pos]=T[pos];
    }
    // メモがあればそのまま返す
    if(M[pos] >= 0){
        return M[pos];
    }
    // なければ探索
    int l = dfs(top+1, left);
    int r = dfs(top+1, left+1);
    if( l > r ){
        M[pos] = T[pos] + l;
    }else{
        M[pos] = T[pos] + r;
    }
    return M[pos];
}

int main(int argc, char** argv){
    cin >> N;
    // 要素数はN(N+1)/2、1-originにするために+1
    int size = N*(N+1)/2 + 1;
    for(int i=1; i<size; i++){
        cin >> T[i];
        M[i] = -1;
    }
    // メモ化再帰
    cout << dfs(1,1);
}
