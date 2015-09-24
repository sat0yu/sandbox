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

vector< vector<bool> > isVisited(12, vector<bool>(12, false));
char seamap[12][12];
pair<int,int> start(0,0);
int numCircle = 0, numCross = 0, numIsland = 0;

void dfs(int x, int y, int depth){
    if( isVisited[x][y] ){ return; }

    isVisited[x][y] = true;

    if(seamap[x][y] == seamap[x+1][y]){
        dfs(x+1, y, depth+1);
    }
    if(seamap[x][y] == seamap[x][y+1]){
        dfs(x, y+1, depth+1);
    }
    if(seamap[x][y] == seamap[x-1][y]){
        dfs(x-1, y, depth+1);
    }
    if(seamap[x][y] == seamap[x][y-1]){
        dfs(x, y-1, depth+1);
    }

    if( (depth == 0) and (seamap[x][y] == 'o') ){
        numIsland++;
    }
};

int main(int argc, char** argv){
    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++){
            cin >> seamap[i][j];
        }
    }
    for(int i=0; i<12; i++){
        seamap[i][0] = '*';
        seamap[i][11] = '*';
        seamap[0][i] = '*';
        seamap[11][i] = '*';
    }

    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++){
            dfs(i,j,0);
        }
    }
    if(numIsland == 1){
        cout << "YES" << endl;
        return 0;
    }

    for(int i=1; i<=10; i++){
        for(int j=1; j<=10; j++){
            if(seamap[i][j] == 'x'){
                numIsland = 0;
                seamap[i][j] = 'o';
                isVisited = vector< vector<bool> >(12, vector<bool>(12, false));
                for(int k=1; k<=10; k++){
                    for(int l=1; l<=10; l++){
                        dfs(k,l,0);
                    }
                }
                if(numIsland == 1){
                    cout << "YES" << endl;
                    return 0;
                }
                seamap[i][j] = 'x';
            }
        }
    }

    cout << "NO" << endl;
    return 0;

}
