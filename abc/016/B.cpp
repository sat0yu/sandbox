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
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    if(a + b == c){
        if(a - b == c){
            printf("?\n");
        }else{
            printf("+\n");
        }
    }else{
        if(a - b == c){
            printf("-\n");
        }else{
            printf("!\n");
        }
    }
    return 0;
}
