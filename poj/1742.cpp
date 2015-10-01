#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>
#include<math.h>

#define MAX(x,y) ( (x)>(y) ? (x) : (y) )
#define MIN(x,y) ( (x)<(y) ? (x) : (y) )

#define MAXN 101
#define MAXM 100001

using namespace std;

int n, m;
int A[MAXN], C[MAXM];
bool M[MAXN][MAXM];

int main(int argc, char** argv){
    while(1){
        cin >> n >> m;
        if(!n && !m){ break; }
        for(int i=1; i<=n; i++){ cin >> A[i]; }
        for(int i=1; i<=n; i++){ cin >> C[i]; }
        // メモ配列は毎回初期化
        memset(M, false, sizeof(M));
        // DP
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                // A_(i-1)までのコインの結果をコピー
                M[i][j] = M[i-1][j];
                // (j - A[i])がA_(i-1)までのコインを使って表現可能ならば
                // A_iのコインを使ってjも表現可能
                if( (j - A[i] > 0) && (M[i-1][j - A[i]]) ){
                    for(int k=1; k<=C[i] && (j - A[i] + A[i]*k < MAXM); k++){
                        M[i][(j - A[i]) + A[i]*k] = true;
                    }
                }
            }
            // A_iのコインだけで表現可能
            for(int j=1; j<=C[i]; j++){
                M[i][ A[i]*j ] = true;
            }
        }
        // 回答出力
        int count=0;
        for(int i=1; i<=m; i++){
            if(M[n][i]){ count++; }
        }
        cout << count << endl;
    }
}
