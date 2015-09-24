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
    int W, N, K;
    cin >> W >> N >> K;
    int SS[50][2];
    for(int i=1; i<=N; i++){
        cin >> SS[i][0] >> SS[i][1];
    }

    vector< vector< vector<int> > > DP(K+1, vector< vector<int> >(N+1, vector<int>(W+1, 0)));
    for(int i=1; i<=K; i++){ // DP
        for(int k=1; k<=W; k++){ // initialize the first line
            if(SS[1][0] <= k){
                DP[i][1][k] = SS[1][1];
            }else{
                DP[i][1][k] = 0;
            }
        }

        for(int j=2; j<=N; j++){
            for(int k=1; k<=W; k++){
                if( ( SS[j][0] <= k ) and ( DP[i-1][j-1][k-SS[j][0]] + SS[j][1] > DP[i][j-1][k] ) ){
                    DP[i][j][k] = DP[i-1][j-1][k-SS[j][0]] + SS[j][1];
                }else{
                    DP[i][j][k] = DP[i][j-1][k];
                }
            }
            // printf("i=%d, j=%d:\t", i, j);
            // for(int k=1; k<=W; k++){
            //     cout << DP[i][j][k] << " ";
            // }
            // cout << endl;
        }
    }
    cout << DP[K][N][W] << endl;
    return 0;
}
