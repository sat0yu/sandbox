#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<math.h>

#define MAX(x,y) ( (x)>(y) ? (x) : (y) )
#define MIN(x,y) ( (x)<(y) ? (x) : (y) )

using namespace std;

int n, k;
unsigned char T[10][10];

bool check(unsigned char uc, int i, int j){
    if(i == n-1){
        return (uc ^ T[i][j]);
    }else if(i == 0){
        for(int l=0; l<k; l++){
            if( !check(T[i][j], i+1, l) ){
                return false;
            }
        }
        return true;
    }else{
        unsigned char xored = (uc ^ T[i][j]);
        for(int l=0; l<k; l++){
            if( !check(xored, i+1, l) ){
                return false;
            }
        }
        return true;
    }
}

int main(int argc, char** argv){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            scanf("%d", &(T[i][j]));
        }
    }

    if( check(0, 0, 0) ){
        printf("Nothing\n");
    }else{
        printf("Found\n");
    }

    return 0;
}
