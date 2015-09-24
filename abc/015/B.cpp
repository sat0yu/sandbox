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
    int cnt=0, sum=0, ai, n;
    cin >> n;
    for(int i=0; i<n; i++){
        scanf("%d", &ai);
        if(ai > 0){
            cnt++;
            sum += ai;
        }
    }
    cout << (int)ceil((double)sum / (double)cnt) << endl;
    return 0;
}
