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
    int n;
    cin >> n;
    if( n == 2 ){
        cout << "WANWAN" << endl;
    }else{
        cout << "BOWWOW" << endl;
    }
    return 0;
}
