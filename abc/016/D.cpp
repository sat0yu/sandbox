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

int p[101][2];

int main(int argc, char** argv){
    int ax,ay,bx,by,n,cross=0;
    scanf("%d %d %d %d", &ax, &ay, &bx, &by);
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &(p[i][0]), &(p[i][1]));
    }

    for(int i=0; i<n; i++){
        int px = p[i+1][0] - p[i][0],
            py = p[i+1][1] - p[i][1];
        if(i == n-1){
            px = p[0][0] - p[i][0];
            py = p[0][1] - p[i][1];
        }
        int ux = ax - p[i][0],
            uy = ay - p[i][1],
            vx = bx - p[i][0],
            vy = by - p[i][1];
        int S1 = 0.5 * (px * uy - ux * py),
            S2 = 0.5 * (px * vy - vx * py);
        if(S1 * S2 < 0){ cross++; }
    }

    cout << (cross/2 + 1) << endl;

    return 0;
}
