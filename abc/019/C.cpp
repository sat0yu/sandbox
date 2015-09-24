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

vector<unsigned char> M(1<<27, 0);
int main(int argc, char** argv){
    int N, res=0;
    unsigned long long a;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
        M[A[i]>>3] |= 1U << (A[i] & 0x07);
    }
    sort(A.begin(), A.end());

    for(int i=0; i<N; i++){
        unsigned long long a = A[i];
        if( M[a>>3] & (1ULL << (a & 0x07)) ){
            // cout << a << endl;
            res++;
        }
        while( a < (1<<27) ){
            M[a>>3] &= ~(1U << (a & 0x07));
            a <<= 1;
        }
    }
    cout << res << endl;
    return 0;
}
