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
    unsigned char xored = uc ^ T[i][j];
    if(i == n-1){
        return xored;
    }else{
        bool tf = true;
        for(int l=0; l<k; l++){
            tf &= check(xored, i+1, l);
        }
        return tf;
    }
}

int main(int argc, char** argv){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            scanf("%d", &(T[i][j]));
        }
    }

    if( check(0U, 0, 0) ){
        printf("Nothing\n");
    }else{
        printf("Found\n");
    }

    return 0;
}
