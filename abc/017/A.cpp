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
    int s1,e1,s2,e2,s3,e3;
    cin >> s1 >> e1 >> s2 >> e2 >> s3 >> e3;
    cout << ((s1*e1)+(s2*e2)+(s3*e3))/10 << endl;
    return 0;
}
