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

unsigned long long A[100001] = {0};
unsigned long long B[100001] = {0};

int main(int argc, char** argv){
    int N, max=0, min=((1UL<<32)-1);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i] >> B[i];
        max = (max > A[i]) ? max : A[i];
        max = (max > B[i]) ? max : B[i];
        min = (min > A[i]) ? A[i] : min;
        min = (min > B[i]) ? B[i] : min;

    }
    for(int i=min; i<=max; i++){
        for(int j=0; j<N; j++){
        }
    }

    return 0;
}
