#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<math.h>

#define _GLIBCXX_DEBUG

#define MAX(x,y) ( (x)>(y) ? (x) : (y) )
#define MIN(x,y) ( (x)<(y) ? (x) : (y) )

#define N 125000000

using namespace std;

int main(int argc, char** argv){
    int NA,NB;
    cin >> NA >> NB;
    vector<unsigned char> bits(N, 0);
    int ai,bi,numerator=0, denominator=NA;
    for(int i=0; i<NA; i++){
        cin >> ai;
        bits[(ai >> 3)] |= (1 << (ai & 0x07));
    }
    for(int i=0; i<NB; i++){
        cin >> bi;
        if( bits[(bi >> 3)] & (1 << (bi & 0x07)) ){
            numerator++;
        }else{
            denominator++;
        };
    }
    printf("%.10f\n", (double)numerator / (double)denominator);
    return 0;
}
