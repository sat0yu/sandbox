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

int dist(int v1, int v2){
    cout << "? " << v1 << " " << v2 << endl;
    int d;
    cin >> d;
    return d;
}

int main(int argc, char** argv){
    int N;
    cin >> N;
    int res=dist(1,2);
    int st=1, en=2;
    for(int i=3; i<=N; i++){
        int e_st = dist(st, i);
        int e_en = dist(en, i);
        if(e_st > res){
            res = e_st;
            en = i;
        }else if(e_en > res){
            res = e_en;
            st = i;
        }
        // printf("st:%d, en:%d, res:%d\n", st, en, res);
    }
    cout << "! " << res << endl;
    cout << flush;
    return 0;
}
