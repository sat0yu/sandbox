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
int A[MAXN], C[MAXN];
// メモ配列は2*mで十分(M[0],M[1]をprev,curとして交互に使用)
// cur[j]に格納するのはコインA[i]の残り使用可能枚数(<C[i])
int M[2][MAXM];

int main(int argc, char** argv){
    while(1){
        cin >> n >> m;
        if(!n && !m){ break; }
        for(int i=1; i<=n; i++){ cin >> A[i]; }
        for(int i=1; i<=n; i++){ cin >> C[i]; }

        // メモ配列は負の値で初期化
        memset(M, -1, sizeof(M));

        // DP
        for(int i=1; i<=n; i++){
            int* prev = M[(i+1)%2];
            int* cur = M[i%2];

            // 0は0枚のコインを使って表現可能
            prev[0] = 0;
            cur[0] = C[i];

            for(int j=1; j<=m; j++){
                // 先にcur[j-A[i]]を確認して、残り利用可能枚数が正ならば
                // デクリメントした値をメモ配列に代入
                if( j - A[i] >= 0 && cur[j - A[i]] > 0 ){
                    cur[j] = cur[j -A[i]] - 1;
                }

                // そもそもA[i]のコインを使わなくても表現可能な場合は
                // 改めてC[i]で上書き
                if( prev[j] >= 0 ){
                    cur[j] = C[i];
                }
            }
        }

        // 回答出力
        int count=0;
        for(int j=1; j<=m; j++){
            // 非負ならば表現可能
            if(M[n%2][j] >= 0){ count++; }
        }
        cout << count << endl;
    }
}
