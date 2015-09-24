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

void swap(vector<int>& blocks, int i, int j){
    int tmp = blocks[i];
    blocks[i] = blocks[j];
    blocks[j] = tmp;
}

int main(int argc, char** argv){
    int N;
    cin >> N;
    vector<int> blocks(N),
                copy1, copy2;
    for(int i=0; i<N; i++){
        cin >> blocks[i];
    }
    copy(blocks.begin(), blocks.end(), back_inserter(copy1));
    copy(blocks.begin(), blocks.end(), back_inserter(copy2));

    int ret1 = 0, ret2 = 0;
    int cidx = (blocks.size()-1)/2;

    for(int i=0; i<cidx; i++){
        for(int j=cidx-1; j>i+1; j++){
            if( copy1[j] < copy1[j-1] ){
                swap(copy1, j, j-1);
                printf("left swap %d,%d\n", j, j-1);
                ret1++;
            }
        }
    }
    for(int i=0; i<cidx; i++){
        for(int j=cidx+1; j<N-i-1; j++){
            if( copy1[j] < copy1[j+1] ){
                printf("right swap %d,%d\n", j, j+1);
                swap(copy1, j, j+1);
                ret1++;
            }
        }
    }
    for(int i=0; i<N; i++){
        printf("%d ", copy1[i]);
    }
    cout << endl;


    // cout << ret1 << "," << ret2 << endl;
    return 0;
}
