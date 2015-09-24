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

int main(int argc, char** argv){
    int m,d;
    scanf("%d %d", &m, &d);
    if(d==0){
        printf("NO\n");
    }else if(m%d){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
    return 0;
}
